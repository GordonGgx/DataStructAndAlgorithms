#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>

/*定义链表元素结构*/
typedef struct ListElmt_
{
    /* 数据 */
    void * data;
    //指向下一个元素的元素
    struct ListElmt_ * next;
} Element;

//定义链表数据结构
typedef struct List_{
    //链表的长度
    int size;
    //查询方法
    int (*match)(const void * key1,const void * key2);
    //链表销毁
    void (*destory)(void (*data));
    //链表的头元素
    Element * head;
    //链表的尾元素
    Element * tail;
} Linked;

//公共接口定义
/*初始化由l参数ist指定的链表，该函数必须在链表做其他操作之前调用。当调用linkedDestory时，destory参数提供了一种释放动态分配的数据的方法，例如如果链表中包含
采用malloc动态分配的数据，当链表被销毁时，destory应该设置为free用来释放数据。对于包含了好几个动态分配成员的结构化数据，destory应该设置为一个用户自定义的析够函数，用过
对每一个动态分配成员以及对结构体自身调用free来释放数据。如果链表包含不应该释放的数据，destory函数应该设置为null*/
void linkedInit(Linked * list,void (*destory)(void * data));

/*销毁有参数list指定的链表。调用该函数后任何其他的操作都不允许执行，除非再次调用init，linkeddestory将链表中所有元素都移除，如果传給init的参数destory不为null，则移除每个元素的时候
都应该调用destory函数*/
void linkedDestory(Linked * list);

/*在list指定的链表element后面插入一个新元素。如果element设置为null，则新元素插入链表头部，新元素包含一个指向data的指针，因此只要该元素还在链表中，data所引用的空间就应该保持合法
。管理data所引用的存储空间是调用者的责任*/
int linkedAdd(Linked * list,Element * element,const void * data);
//追加新元素到链表末尾
int linkedAppend(Linked * list,const void * data);

/*移除由list指定的链表中element后的那个元素。如果element设置为null，则移除链表头部元素。调用返回后，data指向以移除元素中存储的数据。由调用者管理data所引用的存储空间*/
int listRemove(Linked *list,Element * element,void * data);


#define getSize(list) ((list)->size)
#define getHead(list) ((list)->head)
#define getTail(list) ((list)->tail)
#define isHead(list,element) ((element)==(list)->head?1:0)
#define isTail(element) ((element)->next==NULL?1:0)
#define getData(element) ((element)->data)
#define getNext(element) ((element)->next);
#endif