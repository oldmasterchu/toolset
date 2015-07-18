#ifndef HEADERS_BYTES_TOOLS_H_
#define HEADERS_BYTES_TOOLS_H_

#include "../headers/app_types.h"

typedef enum _BytesToolsResult{
	BYTES_TOOLS_RESULT_OK=0,
	BYTES_TOOLS_RESULT_OCT_ERR=-1,
	BYTES_TOOLS_RESULT_LOWER_OCT_ERR=-2,
	BYTES_TOOLS_RESULT_HIGHER_OCT_ERR=-3,
	BYTES_TOOLS_RESULT_INVALID_HEX_STRING_ERR=-4,
	BYTES_TOOLS_RESULT_INVALID_BYTES_INDEX_ERR=-5,
}BytesToolsResult;

#ifdef __cplusplus
extern "C" {
#endif
	BytesToolsResult fillHexFromChar(CHAR octChar,P_BYTE pOct);
	BytesToolsResult fillByteFromHex(CHAR hOct, CHAR lOct, P_BYTE pByte);
	BytesToolsResult fillBytesFromHex(CHAR * hexStr, P_BYTE bytes);
	BytesToolsResult fillLengthAdvanceFromEncodedBytes(BYTE encodedBytes [],unsigned int bytesLength,
								unsigned int offset, unsigned int * length, unsigned int * advance);
	BytesToolsResult fillDataBytesFromEncodedBytes(BYTE encodedBytes [], unsigned int offset,
								BYTE dataBytes []);
#ifdef __cplusplus
}
#endif




#endif /* HEADERS_BYTES_TOOLS_H_ */
