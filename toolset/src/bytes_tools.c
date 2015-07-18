#include "../headers/app_all.h"
#include <string.h>

/* 'char hOct' and 'lOct' respectively represents the high and lower hex digit in a byte
 * function put the 'hOct' and 'lOct' corresponding hex value to the byte pointed by 'pByte'
 *
 * return:
 * BYTES_TOOLS_RESULT_OK				if succeeded
 * BYTES_TOOLS_RESULT_HIGHER_OCT_ERR	if 'hOct' is not representing a valid hex digit
 * BYTES_TOOLS_RESULT_LOWER_OCT_ERR		if 'lOct' is not representing a valid hex digit
 *
 */
BytesToolsResult fillByteFromHex(CHAR hOct, CHAR lOct, P_BYTE pByte){
	unsigned char hOctInt, lOctInt;
	if(fillHexFromChar(hOct, &hOctInt)!=BYTES_TOOLS_RESULT_OK){
		return BYTES_TOOLS_RESULT_HIGHER_OCT_ERR;
	}else{
		if(fillHexFromChar(lOct, &lOctInt)!=BYTES_TOOLS_RESULT_OK){
			return BYTES_TOOLS_RESULT_LOWER_OCT_ERR;
		}else{
			*pByte = 16 * hOctInt+ lOctInt;
			return BYTES_TOOLS_RESULT_OK;
		}
	}
}

/* 'char octChar' represents hex digit
 * function put the corresponding value to unsigned char pointed by 'pOct'
 *
 * return:
 * BYTES_TOOLS_RESULT_OK		if succeeded
 * BYTES_TOOLS_RESULT_OCT_ERR	if 'octChar' is not representing a valid hex digit
 */
BytesToolsResult fillHexFromChar(CHAR octChar,P_BYTE pOct){
	if( octChar>='0' && octChar<='9'){
		*pOct = octChar - '0';
		return BYTES_TOOLS_RESULT_OK;
	}else{
		if(octChar >='a' && octChar<='f'){
			*pOct = octChar -'a' + 10;
			return BYTES_TOOLS_RESULT_OK;

		}else{
			if(octChar >='A' && octChar<='F'){
				*pOct = octChar -'A' + 10;
				return BYTES_TOOLS_RESULT_OK;
			}else{
				return BYTES_TOOLS_RESULT_OCT_ERR;
			}
		}
	}
}

/* 'char * (null terminated string) hexStr' representing stream of bytes
 * and assuming the last byte is the rightmost one
 *
 * function put the corresponding bytes to byte array pointed by 'bytes'
 *
 * return:
 * BYTES_TOOLS_RESULT_OK						if succeeded
 * BYTES_TOOLS_RESULT_INVALID_HEX_STRING_ERR	if 'hexStr' length is invalid
 * BYTES_TOOLS_RESULT_HIGHER_OCT_ERR			if 'hexStr' contains invalid byte representation
 * BYTES_TOOLS_RESULT_LOWER_OCT_ERR				if 'hexStr' contains invalid byte representation
 *
 */
BytesToolsResult fillBytesFromHex(CHAR * hexStr, P_BYTE bytes){
	int n= strlen(hexStr)/2;
	int i;
	if((2*n)!=strlen(hexStr)){
		return BYTES_TOOLS_RESULT_INVALID_HEX_STRING_ERR;
	}
	for (i=0;i<n;i++){
		BytesToolsResult result=fillByteFromHex(hexStr[i*2],hexStr[i*2+1], &bytes[i]);
		if(result!=BYTES_TOOLS_RESULT_OK){
			return result;
		}
	}
	return BYTES_TOOLS_RESULT_OK;
}

/* given bytes stream 'bytes' and
 * function check from 'offset' to get the encoded 'length'
 * the 'advance' indicates where to locate the first data byte
 *
 * return:
 * BYTES_TOOLS_RESULT_OK							if succeeded
 * BYTES_TOOLS_RESULT_INVALID_BYTES_INDEX_ERR		if bytes count to be examined is out of checking range
 */
BytesToolsResult fillLengthAdvanceFromEncodedBytes(BYTE encodedBytes [],unsigned int bytesLength,
		unsigned int offset,unsigned int * length, unsigned int * advance){
	unsigned int nextCount=0;
	unsigned int i;
	BYTE firstByte;

	if((offset) >= bytesLength){
		return BYTES_TOOLS_RESULT_INVALID_BYTES_INDEX_ERR;
	}
	firstByte = encodedBytes[offset];
	if(firstByte<=128){
		*length = firstByte;
		*advance=1;
	}else{
		nextCount=firstByte-128;
		*length=0;
		*advance=1+nextCount;
		for(i=0;i<nextCount;i++){
			if((i+offset) >= bytesLength){
				return BYTES_TOOLS_RESULT_INVALID_BYTES_INDEX_ERR;
			}else{
				*length=*length * 256 + encodedBytes[offset+1+i];
			}
		}
	}


	return BYTES_TOOLS_RESULT_OK;
}



