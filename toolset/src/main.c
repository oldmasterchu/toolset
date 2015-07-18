#include <stdio.h>
#include<stdlib.h>
#include "../headers/app_all.h"


#define BYTES_SIZE 6

int main(){
	CHAR * inputHexStr="A21cc4d5f12a";
	//unsigned char * bytes = malloc(sizeof(unsigned char) * 6);
	BYTE bytes[BYTES_SIZE]={};
	BytesToolsResult result= fillBytesFromHex(inputHexStr, bytes);

	printf("result code : %d\n", (int)result);

	int i=0;
	SimpleByteLinkedList * list=NULL;
	SimpleByteLinkedList * next=NULL;
	SimpleByteLinkedList * curr=NULL;
	list=(SimpleByteLinkedList * )malloc(sizeof(SimpleByteLinkedList));
	list->p_next=NULL;
	list->byte=bytes[0];

	curr=list;
	for(i=1;i<BYTES_SIZE;i++){
		next =(SimpleByteLinkedList * )malloc(sizeof(SimpleByteLinkedList));
		next->byte=bytes[i];
		next->p_next=NULL;
		curr->p_next=next;
		curr=next;
	}

	printByteLinkedList(list);
	return 0;
}
