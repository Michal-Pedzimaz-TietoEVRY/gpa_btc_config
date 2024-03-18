/*****************************************************************************************
 *
 * BOSE CORPORATION
 * COPYRIGHT 2014 BOSE CORPORATION ALL RIGHTS RESERVED
 * This program may not be reproduced, in whole or in part in any
 * form or any means whatsoever without the written permission of:

 *     BOSE CORPORATION
 *     The Mountain
 *     Framingham, MA 01701-9168

 *****************************************************************************************/

/**
 *  @file fireven_hexagon.c
 *  @brief Connects model FIR code generation with hardware accelerator manager
 *
 *  @note Optimization settings for speed should include setting compiler
 *        flags -Ov100 and -ipa (if possible) for the top level build. NDEBUG 
 *        should also be defined to turn off asserts. Also, it is important
 *        to note that this module was NOT designed to support the usage of 
 *        cached data.
 * 
 *  @ingroup dsp
 *
 */

/***  Include Files ***********************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hexagon_sim_timer.h>
#include "fireven_hexagon.h"
#include "hexagon_protos.h"
#include "qhdsp.h"
#include "math.h"

#include "HAP_perf.h"
#define FARF_HIGH 1
#include <HAP_farf.h>

#define COEFF_LENGTH_LARGER_THAN_FRAME_SIZE
#define MAX_FRAME_SIZE                                (32)
#define STACK_SIZE 1024

void fireven_process_lt_thread(void *arg);
void fireven_process_mt_thread(void *arg);
void flt_bkfir(float *xin, float *coefs, int taps, int length, float *yout);
void fireven_process_parallel(float* y,float* x,const unsigned int *activeCoeffSet,float *newstate,unsigned int* workMemory);

/**
 *  fireven_init
 *
 *  @brief Initialization of FIR Even.
 *
 *  @param[in]     frame_size      Number of samples per frame
 *  @param[in]     num_of_ch       Number of channels
 *  @param[in]     num_of_filters  Number of filters
 *  @param[in]     filter_length   Length of filter       
 *  @param[in]     coeffs          Coefficient buffer pointer
 *
 */

void fireven_init(unsigned int *scratchMemory,
		unsigned int frame_size,
		unsigned int num_of_ch,
		unsigned int num_of_filters,
		unsigned int filter_length,
		const float* coeffs,
		unsigned int* workMemory,
		unsigned int maxNumberOfThreads)
{

	int j, k, xtmp_tmp, b_tmp;
	float xtmp;
	FirEven_t* pFir;

	int coeff_size = num_of_filters * filter_length;
	pFir = (FirEven_t*)workMemory;
	pFir->frame_size = frame_size;
	pFir->num_of_ch = num_of_ch;
	pFir->numFilters = num_of_filters;
	pFir->filterLength = filter_length;
	pFir->flippedCoeff = (float*)coeffs;
	pFir->state_offset = 0;
	pFir->rem = frame_size % filter_length;
	pFir->numThreadsToRun = maxNumberOfThreads;

	for (j = 0; j < num_of_filters; j++) {
		for (k = 0; k < (filter_length >> 1); k ++) {
			xtmp_tmp = filter_length * j + k;
			xtmp = pFir->flippedCoeff[xtmp_tmp];
			b_tmp = (filter_length * j - k) + (filter_length - 1);
			pFir->flippedCoeff[xtmp_tmp] = pFir->flippedCoeff[b_tmp];
			pFir->flippedCoeff[b_tmp] = xtmp;
		}
	}

	if(maxNumberOfThreads>1){// if multithreaded

		if(filter_length > frame_size){
			pFir->funcPtr = (void*) fireven_process_mt_thread;
		}
		else{
			pFir->funcPtr = (void*) fireven_process_lt_thread;
		}

		//Thread balancing
		unsigned int tLoad=ceilf((float)num_of_ch/(float)maxNumberOfThreads);

		for(int i=0;i<maxNumberOfThreads-1;i++){
			pFir->thread_arg[i].numChannels=tLoad;
			pFir->thread_arg[i].state_offset = 0;
			pFir->thread_arg[i].startChannel=i*tLoad;
		}
		//sum of number of channels processed by previous threads
		unsigned int lastTLoad = pFir->thread_arg[maxNumberOfThreads-2].startChannel + pFir->thread_arg[maxNumberOfThreads-2].numChannels;

		pFir->thread_arg[maxNumberOfThreads-1].numChannels= num_of_ch - lastTLoad;
		pFir->thread_arg[maxNumberOfThreads-1].state_offset = 0;
		pFir->thread_arg[maxNumberOfThreads-1].startChannel= lastTLoad;

		pFir->numThreadsToRun = maxNumberOfThreads;

#ifdef PTHREAD
		for(int i=0;i<pFir->numThreadsToRun;i++){
			sem_init(&pFir->thread_arg[i].semaWork, 0, 0);
			sem_init(&pFir->thread_arg[i].semaDone, 0, 0);
			pthread_create( &pFir->threads[i], NULL, pFir->funcPtr , (void*) &pFir->thread_arg[i]);
		}
#endif

#ifdef QURTTHREAD
		for(int i=0;i<pFir->numThreadsToRun;i++){

			qurt_sem_init_val(&pFir->thread_arg[i].semaWork,0);
			qurt_sem_init_val(&pFir->thread_arg[i].semaDone,0);

			pFir->thread_stack_addr[i] = malloc(STACK_SIZE);
			qurt_thread_attr_init(&pFir->attr[i]);
			qurt_thread_attr_set_name(&pFir->attr[i], (char *)"cntr1");
			qurt_thread_attr_set_stack_addr(&pFir->attr[i], pFir->thread_stack_addr[i]);
			qurt_thread_attr_set_stack_size(&pFir->attr[i], STACK_SIZE);
			qurt_thread_attr_set_priority(&pFir->attr[i], QURT_THREAD_ATTR_PRIORITY_DEFAULT);

			qurt_thread_create(&pFir->threads[i], &pFir->attr[i], pFir->funcPtr , (void *) &pFir->thread_arg[i]);
		}
#endif
	}
}

/**
 *  fireven_process_mt
 *
 *  @brief Run-time processing of FIR Even.
 *
 *  @param[out]    y               Audio Data Out
 *  @param[in]     x               Audio Data In
 *  @param[in]     activeCoeffSet  
 *  @param[in,out] newstate        State buffer pointer
 *
 */
void fireven_process_mt(float* y,
			float* x,
			unsigned int *activeCoeffSet,
			float *newstate,
			unsigned int* workMemory)
{

		int i, filterLen, framesize, tmp;
		float __attribute__ ((__aligned__(8))) output_b[MAX_FRAME_SIZE];
		float* coof;
		float* xptr;
		float* yptr;
		float* sptr;
		FirEven_t* pFir;

		pFir = (FirEven_t*)workMemory;
		if(pFir->numThreadsToRun==1){
			framesize = pFir->frame_size;
			filterLen = pFir->filterLength;
			xptr = x;
			yptr = y;
			sptr = &newstate[0];
			i = 0;

#ifdef QHL_BLOCK_FIR  
			do {
				coof = pFir->flippedCoeff + activeCoeffSet[i] * filterLen;
				memcpy(sptr + filterLen - 1, xptr, framesize * 4);
				flt_bkfir(sptr, coof, filterLen, framesize, output_b);
				memmove(sptr, (sptr + framesize), (filterLen - 1) * 4);
				memcpy(yptr, output_b, framesize << 2);
				xptr += framesize;
				yptr += framesize;
				sptr += filterLen + framesize;
			} while (++ i < pFir->num_of_ch);
#else
			do {
				coof = pFir->flippedCoeff + activeCoeffSet[i] * filterLen;
				tmp = (framesize | (pFir->state_offset) << 16);

				// Prefetch current filter to L1 (1 cache line -> 2 floats, 8 lines prefetched)
				for (int j=0; j<=filterLen/16;j++ ){
					Q6_dcfetch_A(coof+(16*j));
					Q6_dcfetch_A(sptr+(16*j));
				}

				qhdsp_fir_af(xptr, sptr, coof, filterLen, tmp, output_b);
				memcpy(yptr, output_b, framesize << 2);
				xptr += framesize;
				yptr += framesize;
				sptr += filterLen;
			} while (++ i < pFir->num_of_ch);
			pFir->state_offset = (pFir->state_offset + framesize < filterLen) ? (pFir->state_offset + framesize) : (pFir->state_offset + framesize - filterLen);
#endif // QHL_BLOCK_FIR
		}
		else{
			fireven_process_parallel(y,x,activeCoeffSet,newstate,workMemory);
		}
	}


/**
 *  fireven_process_mt_thread
 *
 *  @brief Run-time threaded processing of FIR Even.
 *
 *  @param[in]     arg      function arguments
 *
 */

void fireven_process_mt_thread(void *arg)
{
	FirEven_thread_args *fir_args_local = (FirEven_thread_args*) arg;
	do{

#ifdef PTHREAD
		sem_wait(&fir_args_local->semaWork);
#endif

#ifdef QURTTHREAD
		qurt_sem_down(&fir_args_local->semaWork);
#endif

		int i, filterLen, framesize, tmp;
		float __attribute__ ((__aligned__(8))) output_b[MAX_FRAME_SIZE];
		float* coof;
		float* xptr;
		float* yptr;
		float* sptr;
		FirEven_t* pFir;

		pFir = (FirEven_t*)fir_args_local->workMemory;
		framesize = pFir->frame_size;
		filterLen = pFir->filterLength;

		xptr = fir_args_local->x+framesize*fir_args_local->startChannel;
		yptr = fir_args_local->y+framesize*fir_args_local->startChannel;
		sptr = &fir_args_local->newstate[0]+filterLen*fir_args_local->startChannel;

		i = fir_args_local->startChannel;

#ifdef QHL_BLOCK_FIR  
	do {
		coof = pFir->flippedCoeff + fir_args_local->activeCoeffSet[i] * filterLen;
		memcpy(sptr + filterLen - 1, xptr, framesize * 4);
		flt_bkfir(sptr, coof, filterLen, framesize, output_b);
		memmove(sptr, (sptr + framesize), (filterLen - 1) * 4);
		memcpy(yptr, output_b, framesize << 2);
		xptr += framesize;
		yptr += framesize;
		sptr += filterLen + framesize;
	} while (++ i < pFir->num_of_ch);      
#else
    do {
		coof = pFir->flippedCoeff + fir_args_local->activeCoeffSet[i] * filterLen;
		tmp = (framesize | (fir_args_local->state_offset) << 16);

		// Prefetch current filter to L1 (1 cache line -> 2 floats, 8 lines prefetched)
		for (int j=0; j<=filterLen/16;j++ ){
			Q6_dcfetch_A(coof+(16*j));
			Q6_dcfetch_A(sptr+(16*j));
		}

		qhdsp_fir_af(xptr, sptr, coof, filterLen, tmp, output_b);
		memcpy(yptr, output_b, framesize << 2);
		xptr += framesize;
		yptr += framesize;
		sptr += filterLen;
	} while (++ i < fir_args_local->startChannel + fir_args_local->numChannels);
	fir_args_local->state_offset = (fir_args_local->state_offset + framesize < filterLen) ? (fir_args_local->state_offset + framesize) : (fir_args_local->state_offset + framesize - filterLen);
#endif // QHL_BLOCK_FIR

	#ifdef PTHREAD
			sem_post(&fir_args_local->semaDone);
	#endif

	#ifdef QURTTHREAD
			qurt_sem_up(&fir_args_local->semaDone);
	#endif

	}while(1);
}

/**
 *  fireven_process_lt
 *
 *  @brief Run-time processing of FIR Even.
 *
 *  @param[out]    y               Audio Data Out
 *  @param[in]     x               Audio Data In
 *  @param[in]     activeCoeffSet
 *  @param[in,out] newstate        State buffer pointer
 *
 */

void fireven_process_lt(float* y,
		float* x,
		unsigned int const *activeCoeffSet,
		float *newstate,
		unsigned int* workMemory)
{

	int i, filterLen, framesize, tmp;
	float __attribute__ ((__aligned__(8))) output_b[MAX_FRAME_SIZE];
	float* coof;
	float* xptr;
	float* yptr;
	float* sptr;
	FirEven_t* pFir;

	pFir = (FirEven_t*)workMemory;
	if(pFir->numThreadsToRun==1){
		framesize = pFir->frame_size;
		filterLen = pFir->filterLength;
		xptr = x;
		yptr = y;
		sptr = &newstate[0];
		i = 0;

#ifdef QHL_BLOCK_FIR
		do {
			coof = pFir->flippedCoeff + activeCoeffSet[i] * filterLen;
			memcpy(sptr + filterLen - 1, xptr, framesize * 4);
			flt_bkfir(sptr, coof, filterLen, framesize, output_b);
			memmove(sptr, (sptr + framesize), (filterLen - 1) * 4);
			memcpy(yptr, output_b, framesize << 2);
			xptr += framesize;
			yptr += framesize;
			sptr += filterLen + framesize;
		} while (++ i < pFir->num_of_ch);
#else
		do{
			coof = pFir->flippedCoeff + activeCoeffSet[i] * filterLen;
			tmp = (framesize | (pFir->state_offset) << 16);

			// Prefetch current filter to L1 (1 cache line -> 2 floats, 8 lines prefetched)
			for (int j=0; j<=filterLen/16;j++ ){
				Q6_dcfetch_A(coof+(16*j));
				Q6_dcfetch_A(sptr+(16*j));
			}

			qhdsp_fir_af(xptr, sptr, coof, filterLen, tmp, output_b);
			memcpy(yptr, output_b, framesize << 2);
			xptr += framesize;
			yptr += framesize;
			sptr += filterLen;
		} while (++ i < pFir->num_of_ch);
		pFir->state_offset = (pFir->state_offset + pFir->rem < filterLen) ? (pFir->state_offset + pFir->rem) : (pFir->state_offset + pFir->rem - filterLen);
#endif  // QHL_BLOCK_FIR
	}
	else{
		fireven_process_parallel(y,x,activeCoeffSet,newstate,workMemory);
	}
}

/**
 *  fireven_process_lt_thread
 *
 *  @brief Run-time thread of FIR Even.
 *
 *  @param[in]     arg      function arguments
 *
 */

void fireven_process_lt_thread(void *arg)
{
	FirEven_thread_args *fir_args_local = (FirEven_thread_args*) arg;
	do{

#ifdef QURTTHREAD
		qurt_sem_down(&fir_args_local->semaWork);
#endif

#ifdef PTHREAD
		sem_wait(&fir_args_local->semaWork);
#endif

		int i, filterLen, framesize, tmp;
		float __attribute__ ((__aligned__(8))) output_b[MAX_FRAME_SIZE];
		float* coof;
		float* xptr;
		float* yptr;
		float* sptr;
		FirEven_t* pFir;

		pFir = (FirEven_t*)fir_args_local->workMemory;
		framesize = pFir->frame_size;
		filterLen = pFir->filterLength;

		xptr = fir_args_local->x+framesize*fir_args_local->startChannel;
		yptr = fir_args_local->y+framesize*fir_args_local->startChannel;
		sptr = &fir_args_local->newstate[0]+filterLen*fir_args_local->startChannel;

		i = fir_args_local->startChannel;
		
#ifdef QHL_BLOCK_FIR    
    do {
        coof = pFir->flippedCoeff + fir_args_local->activeCoeffSet[i] * filterLen;
        memcpy(sptr + filterLen - 1, xptr, framesize * 4);
        flt_bkfir(sptr, coof, filterLen, framesize, output_b);
        memmove(sptr, (sptr + framesize), (filterLen - 1) * 4);
        memcpy(yptr, output_b, framesize << 2);
        xptr += framesize;
        yptr += framesize;
        sptr += filterLen + framesize;
        } while (++ i < pFir->num_of_ch);  
#else
    do {
		coof = pFir->flippedCoeff + fir_args_local->activeCoeffSet[i] * filterLen;
		tmp = (framesize | (fir_args_local->state_offset) << 16);

		// Prefetch current filter to L1 (1 cache line -> 2 floats, 8 lines prefetched)
		for (int j=0; j<=filterLen/16;j++ ){
			Q6_dcfetch_A(coof+(16*j));
			Q6_dcfetch_A(sptr+(16*j));
		}

		qhdsp_fir_af(xptr, sptr, coof, filterLen, tmp, output_b);
		memcpy(yptr, output_b, framesize << 2);
		xptr += framesize;
		yptr += framesize;
		sptr += filterLen;
		} while (++ i < fir_args_local->startChannel+fir_args_local->numChannels);
		fir_args_local->state_offset = (fir_args_local->state_offset + pFir->rem < filterLen) ? (fir_args_local->state_offset + pFir->rem) : (fir_args_local->state_offset + pFir->rem - filterLen);
#endif   // QHL_BLOCK_FIR
    
#ifdef PTHREAD
		sem_post(&fir_args_local->semaDone);
#endif

#ifdef QURTTHREAD
		qurt_sem_up(&fir_args_local->semaDone);
#endif

	}while(1);
}

/**
 *  fireven_process_parallel
 *
 *  @brief Run-time multithread processing of FIR Even.
 *
 *  @param[out]    y               Audio Data Out
 *  @param[in]     x               Audio Data In
 *  @param[in]     activeCoeffSet
 *  @param[in,out] newstate        State buffer pointer
 *
 */

void fireven_process_parallel(float* y,
		float* x,
		const unsigned int *activeCoeffSet,
		float *newstate,
		unsigned int* workMemory)
{
	FirEven_t* pFir;
	pFir = (FirEven_t*)workMemory;

	for(int i=0;i<pFir->numThreadsToRun;i++){
		pFir->thread_arg[i].activeCoeffSet=activeCoeffSet;
		pFir->thread_arg[i].x=x;
		pFir->thread_arg[i].y=y;
		pFir->thread_arg[i].newstate=newstate;
		pFir->thread_arg[i].workMemory=workMemory;
	}

#ifdef PTHREAD
	for(int i=0;i<pFir->numThreadsToRun;i++){
		sem_post(&pFir->thread_arg[i].semaWork);
	}

	for(int i=0;i<pFir->numThreadsToRun;i++){
		sem_wait(&pFir->thread_arg[i].semaDone);
	}
#endif

#ifdef QURTTHREAD

	for(int i=0;i<pFir->numThreadsToRun;i++){
		qurt_sem_up(&pFir->thread_arg[i].semaWork);
	}

	for(int i=0;i<pFir->numThreadsToRun;i++){
		qurt_sem_down(&pFir->thread_arg[i].semaDone);
	}
#endif


}

