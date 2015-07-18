#ifndef HEADERS_APP_TYPES_H_
#define HEADERS_APP_TYPES_H_


typedef unsigned char BYTE;
typedef BYTE * P_BYTE;
typedef char CHAR;


struct _SimpleByteLinkedList{
	BYTE byte;
	struct _SimpleByteLinkedList * p_next;
};

typedef struct _SimpleByteLinkedList SimpleByteLinkedList;

#endif /* HEADERS_APP_TYPES_H_ */
