#ifndef CLINKED_H
#define CLINKED_H
typedef struct CNode_
{
    void * data;
    CNode * next;
} CNode;

typedef struct CLinked_
{
    int size;
    void (*destory)(void * data);
    CNode head;

} CLinked;

void clinked_init(CLinked * linked,void (*destory)(void *data));
void clinked_destory(CLinked * linked);
int clinked_add_next(CLinked * linked,CNode * node,const void * data);
int clinked_remove(CLinked* linked,CNode * node,void * data);

#define clinked_getSize(clinked)((clinked)->size)
#define clinked_getHead(clinked) ((clinked)->head)
#define clinked_getData(node)((node)->data)
#define clinked_getNext(node)((node)->next)


#endif