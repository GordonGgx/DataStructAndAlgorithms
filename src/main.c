#include <stdio.h>
#include "linked.h"
#include "dlinked.h"
void testLinked(){
	Linked list;
	linkedInit(&list,NULL);
	linkedAppend(&list,"uuu");
	linkedAppend(&list,"ggx");
	linkedAppend(&list,"xtt");
	linkedAppend(&list,"xll");
	linkedAppend(&list,"xxx");
	Element * head=getHead(&list);
	linkedAdd(&list,head,"yyy");
	printf("链表长度%d\n",getSize(&list));
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
}

void testDLinked(){
	DLinked dlinked;
	dlinked_init(&dlinked,NULL);

}
int main() {
	// testLinked();
	testDLinked();
	getchar();
}