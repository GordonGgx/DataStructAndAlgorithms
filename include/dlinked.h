#ifndef DLINKED_H
#define DLINKED_H
typedef struct Node_
{   
    //元素所存储的数据
    void *data;
    //当前元素指向上一个元素的地址
    Node * previous;
    //当前元素指向下一个元素的地址
    Node * next;
} Node;

typedef struct DLinked_
{
    //链表长度
    int size;
    //链表头元素地址
    Node * head;
    //链表尾节点地址
    Node * tail;
    //链表销毁的方法地址
    void (*destory)(void * data);
} DLinked;

void dlinked_init(DLinked * list,void (*destory)(void *data));
void dlinked_destory(DLinked * list);
int dlinked_add_next(DLinked * list,Node * node,const void * data);
int dlinked_add_prev(DLinked * list,Node * node,const void * data);
int dlinked_remove(DLinked * list,Node * node,void ** data);

#define dlinked_getSize(dlist) ((dlist)->size)
#define dlinked_getTail(list) ((list)->tail)
#define dlinked_getHead(list) ((list)->head)
#define dlinked_isHead(node) ((node)->previous==NULL?1:0)
#define dlinked_isTail(node) ((node)->next==NULL?1:0)
#define dlinked_isEmpty(list) ((list)->size==0?1:0);
#define dlinked_getData(node) ((node)->data)
#define dlinked_getNext(node) ((node)->next)
#define dlinked_getPrevious(node) ((node)->previous)
#endif