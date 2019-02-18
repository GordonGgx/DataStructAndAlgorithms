#include <stdio.h>
#include "list.h"
int main() {
	Linked list;
	listInit(&list,NULL);
	linkedAppend(&list,"ggx");
	linkedAppend(&list,"xtt");
	linkedAppend(&list,"xll");
	linkedAppend(&list,"xxx");
	Element * head=getHead(&list);
	listAdd(&list,head,"yyy");
	printf("链表长度%d\n",size(&list));
	char * data=((char *)getData(head));
	printf("头元素=%s\n",data);
	Element * tail=getTail(&list);
	printf("尾元素%s\n",(char * )getData(tail));

	Element * el=getNext(head);
	while(el!=NULL){
		char * d=(char *)getData(el);
		printf("%s\n",d);
		el=getNext(el);
	}
	
	linkedDestory(&list);
	getchar();
}