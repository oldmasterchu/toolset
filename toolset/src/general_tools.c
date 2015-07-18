#include "../headers/general_tools.h"
#include <stdio.h>
#include <stdlib.h>

void freeByteLinkedList(SimpleByteLinkedList * listHead){
	if(listHead==NULL)
		return;
	SimpleByteLinkedList * p_current=listHead; /* actually point to the head */
	SimpleByteLinkedList * p_next=p_current->p_next;
	while(p_current!=NULL){
		printf("free one: %02X\n",p_current->byte);
		free(p_current);
		p_current=p_next;
		if(p_current==NULL)
			break;
		p_next=p_current->p_next;
	}
}

void printByteLinkedList(SimpleByteLinkedList * listHead){
	SimpleByteLinkedList * p_current=listHead; /* actually point to the head */
	SimpleByteLinkedList * p_next=p_current->p_next;
	while(p_current!=NULL){
		printf("%02X->",p_current->byte);
		p_current=p_next;
		if(p_current==NULL){
			printf("END\n");
			break;
		}
		p_next=p_current->p_next;
	}
}
