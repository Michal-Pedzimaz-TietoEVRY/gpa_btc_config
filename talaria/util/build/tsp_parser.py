#!/usr/bin/env python
###############################################################################
#
# BOSE CORPORATION
# COPYRIGHT (c) BOSE CORPORATION ALL RIGHTS RESERVED
# self program may not be reproduced, in whole or in part in any
# form or any means whatsoever without the written permission of:
# BOSE CORPORATION
# The Mountain
# Framingham, MA 01701-9168
#
# translation_engine Loads a translation engine into python.
#   Given the full path of the dll corresponding to the translation engine
#   self routine loads the dll. If successful, 
#   the resulting object can be used to access the translation engine.
# Note: The translation engine must be built with the same
# machine architecture as the python (i.e. 64 vs. 32 bit)
################################################################################
import sys
import warnings
import os
import xml.etree.ElementTree as ET
from collections import namedtuple
from payload_parser import payload_parser

class tsp_parser:
    '''
    tsp_parser Loads the generated TSP_Tokens.xml file and enables
    conversion between binary-packed payloads and string representations of
    TSP payloads
    '''
    def __init__(self, TspTokensXmlFilePath, isLittleEndian=True):
        '''
        tsp_parser Constructs a TSP parser object.
        Given a TSP_Tokens.XML file to describe the tokens. Payload definitions are
        manually known and described within this class
        '''
        if (False == os.path.isfile(TspTokensXmlFilePath)):
            raise Exception('Could not find TSP XML file %s' % TspTokensXmlFilePath)
        else:
            self.XmlFilePath = TspTokensXmlFilePath

        self.isLittleEndian = isLittleEndian
        payload_parser.isLittleEndian = isLittleEndian
        tree = ET.parse(self.XmlFilePath)

        self.MapFPathToTspInfoStruct = dict()
        self.MapBlindReadTokenToFPath = dict()
        self.MapAddTokenToFPath = dict()
        self.MapSubTokenToFPath = dict()
        self.MapRetrieveTokenToFPath = dict()
        self.MapCaptureTokenToCoreIndex = dict()
        self.MapClearTokenToCoreIndex = dict()
        self.MapCoreIndexToCoreInfoStruct = dict()
        for elem in tree.iter():
            if elem.tag == 'TSP':
                attribute = elem.attrib
                id = attribute.get('id')
                blindReadToken = attribute.get('blindReadToken')
                addToken = attribute.get('addToken')
                subToken = attribute.get('subToken')
                retrieveToken = attribute.get('retrieveToken')
                self.MapFPathToTspInfoStruct[id] = attribute
                self.MapBlindReadTokenToFPath[blindReadToken] = id
                self.MapAddTokenToFPath[addToken] = id
                self.MapSubTokenToFPath[subToken] = id
                self.MapRetrieveTokenToFPath[retrieveToken] = id
            elif elem.tag == 'Core':
                attribute = elem.attrib
                captureToken = attribute.get('captureToken')
                clearToken = attribute.get('clearToken')
                coreIndex = attribute.get('coreIndex')
                self.MapCaptureTokenToCoreIndex[captureToken] = coreIndex
                self.MapClearTokenToCoreIndex[clearToken] = coreIndex
                self.MapCoreIndexToCoreInfoStruct[coreIndex] = attribute

    def GetBlindReadToken(self, featurePath):
        '''
        GetReadToken returns string hex token for the specified
        TSP featurePath string.
        '''
        mapStruct = self.MapFPathToTspInfoStruct[featurePath]
        readToken = mapStruct.get('blindReadToken')
        return readToken
    
    def GetAddToken(self, featurePath):
        '''
        GetReadToken returns string hex token for the specified
        TSP featurePath string.
        '''
        mapStruct = self.MapFPathToTspInfoStruct[featurePath]
        readToken = mapStruct.get('addToken')
        return readToken

    def GetSubToken(self, featurePath):
        '''
        GetReadToken returns string hex token for the specified
        TSP featurePath string.
        '''
        mapStruct = self.MapFPathToTspInfoStruct[featurePath]
        readToken = mapStruct.get('subToken')
        return readToken

    def GetRetrieveToken(self, featurePath):
        '''
        GetReadToken returns string hex token for the specified
        TSP featurePath string.
        '''
        mapStruct = self.MapFPathToTspInfoStruct[featurePath]
        readToken = mapStruct.get('retrieveToken')
        return readToken

    def GetCaptureToken(self, coreIndex):
        '''
        GetCaptureToken returns string hex token for the specified
        TSP triggered capture.
        GetCaptureToken(self,1)
        '''
        coreIndexStr = str(coreIndex)
        mapStruct = self.MapCoreIndexToCoreInfoStruct[coreIndexStr]
        captureToken = mapStruct.get('captureToken')
        return captureToken

    def GetClearToken(self, coreIndex):
        '''
        GetClearToken returns string hex token for the specified
        TSP triggered capture list clear.
        GetClearToken(self,1)
        '''
        coreIndexStr = str(coreIndex)
        mapStruct = self.MapCoreIndexToCoreInfoStruct[coreIndexStr]
        clearToken = mapStruct.get('clearToken')
        return clearToken

    def PackTspBlindRead(self, featurePath, charOffset=0, charCount=''):
        '''
        PackTspBlindRead packs a binary TSP blindread
        request 
        Usage:
           binaryPayload = PackTspBlindRead(self, featurePath, charOffset, charCount)
                
        See also: ext_port_model.HandleAsdIdRequest
        '''
        tspInfoStruct = self.MapFPathToTspInfoStruct[featurePath]
        # Understand datatype's size in count of uint8s
        dtBytes, dataType = payload_parser.GetDataTypeBytes(tspInfoStruct.get('dataType'))

        if (charCount == ''):
            # By default, grab the whole thing!
            charCount = int(tspInfoStruct.get('width')) * dtBytes

        signalsList = "msgId callerHandle charOffset charCount"
        signalValueList = [
            str(tspInfoStruct.get('blindReadToken')),   # msgId
            "0",                                        # callerHandle
            str(charOffset),                            # charOffset
            str(charCount)                              # charCount                
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = [tspInfoStruct.get('id') + ' Blind Read']
        return PackHelper(featurePath, signalNames, srcStrArray)

    def PackTspListAdd(self, featurePath, captureCount=1, skipInterval=0):
        '''
        PackTspListAdd packs a binary TSP list add
        request 
        Usage:
           binaryPayload = PackTspListAdd(self, featurePath, captureCount, skipInterval)
        
        See also: ext_port_model.HandleAsdIdRequest
        '''
        tspInfoStruct = self.MapFPathToTspInfoStruct[featurePath]
        # Understand datatype's size in count of uint8s
        dtBytes, dataType = payload_parser.GetDataTypeBytes(tspInfoStruct.get('dataType'))

        signalsList = "msgId callerHandle captureCount skipInterval"
        signalValueList = [
            str(tspInfoStruct.get('addToken')),     # msgId
            "0",                                    # callerHandle
            str(captureCount),                      # charOffset
            str(skipInterval)                       # charCount                
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = [tspInfoStruct.get('id') + ' List Add']
        return PackHelper(featurePath, signalNames, srcStrArray)

    def PackTspListSub(self, featurePath):
        '''
        PackTspListSub packs a binary TSP list subtraction
        request 
        Usage:
           binaryPayload = PackTspListSub(self, featurePath)
        
        See also: ext_port_model.HandleAsdIdRequest
        '''
        tspInfoStruct = self.MapFPathToTspInfoStruct[featurePath]
        # Understand datatype's size in count of uint8s
        dtBytes, dataType = payload_parser.GetDataTypeBytes(tspInfoStruct.get('dataType'))

        signalsList = "msgId callerHandle"
        signalValueList = [
            str(tspInfoStruct.get('subToken')), # msgId
            "0"                                 # callerHandle
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = [tspInfoStruct.get('id') + ' List Subtract']
        return PackHelper(featurePath, signalNames, srcStrArray)

    def PackTspRetrieve(self, featurePath, captureIndex=0, charOffset=0, charCount=''):
        '''
        PackTspListSub packs a binary TSP captured data retrieval
        request 
        Usage:
           binaryPayload = PackTspRetrieve(self, featurePath,captureIndex,charOffset,charCount)
        
        See also: ext_port_model.HandleAsdIdRequest
        '''
        tspInfoStruct = self.MapFPathToTspInfoStruct[featurePath]
        # Understand datatype's size in count of uint8s
        dtBytes, dataType = payload_parser.GetDataTypeBytes(tspInfoStruct.get('dataType'))

        if (charCount == ''):
            # By default, retrieve the whole thing for self index
            charCount = int(tspInfoStruct.get('width')) * dtBytes

        signalsList = "msgId callerHandle captureIndex charOffset charCount"
        signalValueList = [
            str(tspInfoStruct.get('retrieveToken')),    # msgId
            "0",                                        # callerHandle
            str(captureIndex),                          # captureIndex
            str(charOffset),                            # charOffset
            str(charCount)                              # charCount
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = [tspInfoStruct.get('id') + ' Capture Retrieval']
        return PackHelper(featurePath, signalNames, srcStrArray)

    def PackTspCapture(self, coreIndex):
        '''
        PackTspCapture creates a binary payload to trigger a capture
        on the core indicated.
        Usage:
          binaryPayload = PackTspCapture(self,coreIndex)
        e.g. reqBin = obj.PackTspCapture(1)
        '''
        captureToken = self.GetCaptureToken(coreIndex)
        signalsList = "msgId callerHandle"
        signalValueList = [
            captureToken,   # msgId
            "0"             # callerHandle
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = 'Trigger capture on core %d' % coreIndex
        return PackHelper(featurePath, signalNames, srcStrArray)

    def PackTspClear(self, coreIndex):
        '''
        PackTspClear creates a binary payload to clear thecapture
        list on the core indicated.
        Usage:
          binaryPayload = PackTspClear(self,coreIndex)
        e.g. reqBin = obj.PackTspClear(1)
        '''
        captureToken = self.GetClearToken(coreIndex)
        signalsList = "msgId callerHandle"
        signalValueList = [
            captureToken,   # msgId
            "0"             # callerHandle
            ]
        signalNames = signalsList.split()
        srcStrArray = signalValueList
        featurePath = 'Clear capture list on core %d' % coreIndex
        return PackHelper(featurePath, signalNames, srcStrArray)

    def UnpackRequest(self, binaryPayload):
        return self.UnpackPayload(binaryPayload, True)

    def UnpackResponse(self, binaryPayload):
        return self.UnpackPayload(binaryPayload, False)

    def UnpackPayload(self, binaryPayload, isRequest=False):
        '''
        UnpackPayload Returns a MATLAB struct given a binary payload
        and the knowledge of whether to unpack a request or response.
        If not provided, isRequest is assumed false
        Usage:
          theStruct = objUnpackPayload(self,binaryPayload, isRequest)
        '''

        # Retrieve the token from the payload
        byteArr = bytearray(binaryPayload[0:4])
        if self.isLittleEndian:
            token = int.from_bytes(byteArr, byteorder='little', signed=False)
        else:
            token = int.from_bytes(byteArr, byteorder='big', signed=False)
        tokenStr = "0x{:08x}".format(token)

        class Struct():
            pass
        theStruct = Struct()
        theStruct.CalcToken = tokenStr

        # Assume the payload might have typed data
        hasData = True

        # Determine which of the 4 types of payloads to unpack
        # (TODO does not yet recognize trigger-capture or clear-list)
        if (tokenStr in self.MapBlindReadTokenToFPath):
            # self is a BLIND READ
            featurePath = self.MapBlindReadTokenToFPath[tokenStr]
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP Blind Read Request'
                signalsList = "msgId callerHandle charOffset charCount"
            else:
                theStruct.CalcPayloadType = 'TSP Blind Read Response'
                signalsList = "tspId callerHandle statusCode charCount data"
        elif (tokenStr in self.MapAddTokenToFPath):
            # self is a LIST ADD
            featurePath = self.MapAddTokenToFPath[tokenStr]
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP List Add Request'
                signalsList = "msgId callerHandle captureCount skipInterval"
            else:
                theStruct.CalcPayloadType = 'TSP List Add Response'
                signalsList = "msgId callerHandle statusCode"
        elif (tokenStr in self.MapSubTokenToFPath):
            # self is a LIST SUB
            featurePath = self.MapSubTokenToFPath[tokenStr]
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP List Subtract Request'
                signalsList = "msgId callerHandle"
            else:
                theStruct.CalcPayloadType = 'TSP List Subract Response'
                signalsList = "msgId callerHandle statusCode"
        elif (tokenStr in self.MapRetrieveTokenToFPath):
            # self is a RETRIEVE
            featurePath = self.MapRetrieveTokenToFPath[tokenStr]
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP Retrieve Request'
                signalsList = "msgId callerHandle captureIndex charOffset charCount"
            else:
                theStruct.CalcPayloadType = 'TSP Retrieve Response'
                signalsList = "msgId callerHandle statusCode charCount data"
        elif (tokenStr in self.MapCaptureTokenToCoreIndex):
            # self is a Capture
            hasData = False
            coreIndexStr = self.MapCaptureTokenToCoreIndex[tokenStr]
            featurePath = 'Capture on core %s' % coreIndexStr
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP Capture Request'
                signalsList = "msgId callerHandle"
            else:
                # Capture response assumed, but will automatically
                # adjust to become notification based on discovered
                # statusCode
                theStruct.CalcPayloadType = 'TSP Capture Response'
                signalsList = "msgId callerHandle statusCode"
        elif (tokenStr in self.MapClearTokenToCoreIndex):
            # self is a Clear of the list
            hasData = False
            coreIndexStr = self.MapClearTokenToCoreIndex[tokenStr]
            featurePath = 'Capture on core %s' % coreIndexStr
            if (isRequest):
                theStruct.CalcPayloadType = 'TSP Clear List Request'
                signalsList = "msgId callerHandle"
            else:
                theStruct.CalcPayloadType = 'TSP Clear List Response'
                signalsList = "msgId callerHandle statusCode"
        else:
            raise Exception('Token [%s] is not recognized as a TSP token for [%s]' % (tokenStr,self.ModelName))

        # Understand TSP's datatype and size in count of uint8s
        theStruct.CalcFeaturePath = featurePath
        if (hasData):
            tspInfoStruct = self.MapFPathToTspInfoStruct[featurePath]
            dtBytes, dataType = payload_parser.GetDataTypeBytes(tspInfoStruct.get('dataType'))

        # Use a payload_parser specStruct to help unpack the request
        specStruct = payload_parser.InitSpecStruct()
        specStruct.featurePath = featurePath
        specStruct.binaryPayload = binaryPayload
        
        # Pull out all signals using XML doc as payload specification
        signalNames = signalsList.split()
        i = 0
        while i < len(signalNames):
            specStruct.sigName = str(signalNames[i])
            if (hasData and "data" == signalNames[i]):
                # the data payload element is variable size and type
                specStruct.dataType = tspInfoStruct.dataType
                specStruct.width = theStruct.charCount / dtBytes
                # Include additional "calculated" information in result
                theStruct.CalcTspDatatype = tspInfoStruct.dataType
                theStruct.CalcWidth = specStruct.width
            else:
                specStruct.width = 1
                specStruct.dataType = GetSigDataType(specStruct.sigName)

            [theStruct,specStruct] = payload_parser.UnpackPayloadElement(theStruct,specStruct)
            # If a status code has just been unpacked, also include
            # it's string translation:
            if ("statusCode" == signalNames[i]):
                theStruct.CalcStatusCodeStr = payload_parser.GetStatusCodeStr(theStruct.statusCode)
                if (payload_parser.GetNotificationCode == theStruct.statusCode):
                    # self is a notification! Change payload format:
                    theStruct.CalcPayloadType = 'TSP Capture Complete Notification'
                    signalsList = "msgId callerHandle statusCode totalCaptureCount"
                    signalNames = signalsList.split
                elif(0 != theStruct.statusCode):
                    # self is a failure status response. There are no
                    # more expected contents for the payload
                    break
            i = i+1

        # Diagnostic information
        unparsedCount = len(binaryPayload) - specStruct.charItr
        if (0 < unparsedCount):
            theStruct.CalcUnparsedBytes = unparsedCount
            warnings.warn('[%d] additional bytes in payload that were not parsed' % unparsedCount)

        return theStruct
    
# Local helper def (e.g. like private static, but without hassle)
def GetSigDataType(sigName):
    if(sigName == 'statusCode'):
        dataType = 'int32'
    else:
        dataType = 'uint32'
    return dataType

def PackHelper(featurePath,signalNames,srcStrArray):
    # Use a payload_parser specStruct to help pack the request
    specStruct = payload_parser.InitSpecStruct()
    specStruct.featurePath = featurePath

    for i in range(len(signalNames)):
        specStruct.sigName = signalNames[i]
        specStruct.dataType = GetSigDataType(specStruct.sigName)
        specStruct.width = 1
        srcStrArray, specStruct = payload_parser.PackPayloadElement(srcStrArray, specStruct)
    return specStruct.binaryPayload
