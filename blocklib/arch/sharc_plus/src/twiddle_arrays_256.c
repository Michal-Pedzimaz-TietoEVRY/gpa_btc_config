/*******************************************************************************
* BOSE CORPORATION
* COPYRIGHT (c) BOSE CORPORATION ALL RIGHTS RESERVED
* This program may not be reproduced, in whole or in part in any
* form or any means whatsoever without the written permission of:
* BOSE CORPORATION
* The Mountain
* Framingham, MA 01701-9168
********************************************************************************
* Title: Twiddle factors for 256 point complex FFT
* Revision: $Header$
* Description:%save
* These twiddle factors are for the cfftf() function in the Analog Devices
* math library. The array twiddle_r contains positive cosine factors, and 
* twiddle_i contains the negative sine factors, each of size fftSize/2.
*******************************************************************************/
#include "twiddle.h"

void set_twiddle_256(unsigned int *twiddle_r, unsigned int *twiddle_i)
{
    *twiddle_r = (unsigned int) twiddle256_r;
    *twiddle_i = (unsigned int) twiddle256_i;
}

#pragma section("seg_l1_dmda")
float dm twiddle256_r[] = {
1.00000000000000000e+000, 
9.99698818696204250e-001, 
9.98795456205172410e-001, 
9.97290456678690210e-001, 
9.95184726672196930e-001, 
9.92479534598709970e-001, 
9.89176509964781010e-001, 
9.85277642388941220e-001, 
9.80785280403230430e-001, 
9.75702130038528570e-001, 
9.70031253194543970e-001, 
9.63776065795439840e-001, 
9.56940335732208820e-001, 
9.49528180593036670e-001, 
9.41544065183020810e-001, 
9.32992798834738960e-001, 
9.23879532511286740e-001, 
9.14209755703530690e-001, 
9.03989293123443340e-001, 
8.93224301195515320e-001, 
8.81921264348355050e-001, 
8.70086991108711460e-001, 
8.57728610000272120e-001, 
8.44853565249707120e-001, 
8.31469612302545240e-001, 
8.17584813151583710e-001, 
8.03207531480644940e-001, 
7.88346427626606340e-001, 
7.73010453362736990e-001, 
7.57208846506484570e-001, 
7.40951125354959220e-001, 
7.24247082951467000e-001, 
7.07106781186547570e-001, 
6.89540544737066940e-001, 
6.71558954847018440e-001, 
6.53172842953776870e-001, 
6.34393284163645490e-001, 
6.15231590580626820e-001, 
5.95699304492433470e-001, 
5.75808191417845340e-001, 
5.55570233019602290e-001, 
5.34997619887097260e-001, 
5.14102744193221660e-001, 
4.92898192229784090e-001, 
4.71396736825997810e-001, 
4.49611329654606600e-001, 
4.27555093430282200e-001, 
4.05241314004989860e-001, 
3.82683432365089840e-001, 
3.59895036534988280e-001, 
3.36889853392220050e-001, 
3.13681740398891570e-001, 
2.90284677254462330e-001, 
2.66712757474898420e-001, 
2.42980179903263980e-001, 
2.19101240156869770e-001, 
1.95090322016128330e-001, 
1.70961888760301360e-001, 
1.46730474455361750e-001, 
1.22410675199216280e-001, 
9.80171403295607700e-002, 
7.35645635996674540e-002, 
4.90676743274181260e-002, 
2.45412285229122640e-002, 
6.12323399573676600e-017, 
-2.45412285229121420e-002, 
-4.90676743274180080e-002, 
-7.35645635996673290e-002, 
-9.80171403295606450e-002, 
-1.22410675199216150e-001, 
-1.46730474455361640e-001, 
-1.70961888760301240e-001, 
-1.95090322016128190e-001, 
-2.19101240156869660e-001, 
-2.42980179903263870e-001, 
-2.66712757474898310e-001, 
-2.90284677254462160e-001, 
-3.13681740398891410e-001, 
-3.36889853392219940e-001, 
-3.59895036534988170e-001, 
-3.82683432365089730e-001, 
-4.05241314004989750e-001, 
-4.27555093430281860e-001, 
-4.49611329654606710e-001, 
-4.71396736825997700e-001, 
-4.92898192229783980e-001, 
-5.14102744193221550e-001, 
-5.34997619887097040e-001, 
-5.55570233019601960e-001, 
-5.75808191417845340e-001, 
-5.95699304492433360e-001, 
-6.15231590580626710e-001, 
-6.34393284163645380e-001, 
-6.53172842953776530e-001, 
-6.71558954847018440e-001, 
-6.89540544737066940e-001, 
-7.07106781186547460e-001, 
-7.24247082951466780e-001, 
-7.40951125354958880e-001, 
-7.57208846506484680e-001, 
-7.73010453362736990e-001, 
-7.88346427626606230e-001, 
-8.03207531480644830e-001, 
-8.17584813151583600e-001, 
-8.31469612302545350e-001, 
-8.44853565249707120e-001, 
-8.57728610000272010e-001, 
-8.70086991108711350e-001, 
-8.81921264348354940e-001, 
-8.93224301195515210e-001, 
-9.03989293123443340e-001, 
-9.14209755703530690e-001, 
-9.23879532511286740e-001, 
-9.32992798834738850e-001, 
-9.41544065183020700e-001, 
-9.49528180593036670e-001, 
-9.56940335732208820e-001, 
-9.63776065795439840e-001, 
-9.70031253194543970e-001, 
-9.75702130038528460e-001, 
-9.80785280403230430e-001, 
-9.85277642388941220e-001, 
-9.89176509964781010e-001, 
-9.92479534598709970e-001, 
-9.95184726672196820e-001, 
-9.97290456678690210e-001, 
-9.98795456205172410e-001, 
-9.99698818696204250e-001};

#pragma section("seg_l1_pmda")
float pm twiddle256_i[] = {
0.00000000000000000e+000, 
-2.45412285229122880e-002, 
-4.90676743274180150e-002, 
-7.35645635996674260e-002, 
-9.80171403295606040e-002, 
-1.22410675199216200e-001, 
-1.46730474455361750e-001, 
-1.70961888760301220e-001, 
-1.95090322016128250e-001, 
-2.19101240156869800e-001, 
-2.42980179903263870e-001, 
-2.66712757474898370e-001, 
-2.90284677254462330e-001, 
-3.13681740398891520e-001, 
-3.36889853392220050e-001, 
-3.59895036534988110e-001, 
-3.82683432365089780e-001, 
-4.05241314004989860e-001, 
-4.27555093430282080e-001, 
-4.49611329654606540e-001, 
-4.71396736825997640e-001, 
-4.92898192229784040e-001, 
-5.14102744193221660e-001, 
-5.34997619887097150e-001, 
-5.55570233019602180e-001, 
-5.75808191417845340e-001, 
-5.95699304492433360e-001, 
-6.15231590580626820e-001, 
-6.34393284163645490e-001, 
-6.53172842953776760e-001, 
-6.71558954847018330e-001, 
-6.89540544737066830e-001, 
-7.07106781186547460e-001, 
-7.24247082951466890e-001, 
-7.40951125354959110e-001, 
-7.57208846506484570e-001, 
-7.73010453362736880e-001, 
-7.88346427626606230e-001, 
-8.03207531480644830e-001, 
-8.17584813151583710e-001, 
-8.31469612302545240e-001, 
-8.44853565249707010e-001, 
-8.57728610000272120e-001, 
-8.70086991108711350e-001, 
-8.81921264348354940e-001, 
-8.93224301195515320e-001, 
-9.03989293123443340e-001, 
-9.14209755703530690e-001, 
-9.23879532511286740e-001, 
-9.32992798834738850e-001, 
-9.41544065183020810e-001, 
-9.49528180593036670e-001, 
-9.56940335732208940e-001, 
-9.63776065795439840e-001, 
-9.70031253194543970e-001, 
-9.75702130038528570e-001, 
-9.80785280403230430e-001, 
-9.85277642388941220e-001, 
-9.89176509964781010e-001, 
-9.92479534598709970e-001, 
-9.95184726672196820e-001, 
-9.97290456678690210e-001, 
-9.98795456205172410e-001, 
-9.99698818696204250e-001, 
-1.00000000000000000e+000, 
-9.99698818696204250e-001, 
-9.98795456205172410e-001, 
-9.97290456678690210e-001, 
-9.95184726672196930e-001, 
-9.92479534598709970e-001, 
-9.89176509964781010e-001, 
-9.85277642388941220e-001, 
-9.80785280403230430e-001, 
-9.75702130038528570e-001, 
-9.70031253194543970e-001, 
-9.63776065795439840e-001, 
-9.56940335732208940e-001, 
-9.49528180593036670e-001, 
-9.41544065183020810e-001, 
-9.32992798834738850e-001, 
-9.23879532511286740e-001, 
-9.14209755703530690e-001, 
-9.03989293123443450e-001, 
-8.93224301195515210e-001, 
-8.81921264348355050e-001, 
-8.70086991108711460e-001, 
-8.57728610000272120e-001, 
-8.44853565249707230e-001, 
-8.31469612302545350e-001, 
-8.17584813151583710e-001, 
-8.03207531480644940e-001, 
-7.88346427626606340e-001, 
-7.73010453362737100e-001, 
-7.57208846506484680e-001, 
-7.40951125354958990e-001, 
-7.24247082951466890e-001, 
-7.07106781186547570e-001, 
-6.89540544737067050e-001, 
-6.71558954847018550e-001, 
-6.53172842953776640e-001, 
-6.34393284163645490e-001, 
-6.15231590580626930e-001, 
-5.95699304492433470e-001, 
-5.75808191417845450e-001, 
-5.55570233019602180e-001, 
-5.34997619887097150e-001, 
-5.14102744193221770e-001, 
-4.92898192229784150e-001, 
-4.71396736825997860e-001, 
-4.49611329654606870e-001, 
-4.27555093430282030e-001, 
-4.05241314004989920e-001, 
-3.82683432365089890e-001, 
-3.59895036534988330e-001, 
-3.36889853392220330e-001, 
-3.13681740398891410e-001, 
-2.90284677254462390e-001, 
-2.66712757474898480e-001, 
-2.42980179903264070e-001, 
-2.19101240156870050e-001, 
-1.95090322016128610e-001, 
-1.70961888760301220e-001, 
-1.46730474455361800e-001, 
-1.22410675199216350e-001, 
-9.80171403295608260e-002, 
-7.35645635996677320e-002, 
-4.90676743274179660e-002, 
-2.45412285229123260e-002};

