#include <stdlib.h>
#include <string.h>
#include "linked.h"

void linkedInit(Linked * list,void (*destory)(void * data)){
    list->size=0;
    list->head=NULL;
    list->tail=NULL;
    list->destory=destory;
}

void linkedDestory(Linked * list){
    void * data;
    while(getSize(list)>0){
        if(listRemove(list,NULL,(void **)&data)==0 && 
            list->destory!=NULL){
                list->destory(data);
            }
    }
    //清除这块结构体内存
    memset(list,0,sizeof(Linked));
}

int linkedAdd(Linked * list,Element * element,const void * data){
    Element * newElement;
    //分配内存给新的元素，如果失败则直接返回-1
    if((newElement=(Element *)malloc(sizeof(Element)))==NULL){
        return -1;
    }
    //插入新元素到Linked中
    newElement->data=data;
    if(element==NULL){
        //新元素添加到链表头部
        //如果当前列表元素数量为0则链表末尾元素就是头元素
        if (getSize(list)==0) {
            list->tail==newElement;
        }
        //将新元素的下一个元素指向旧列表中的首位元素
        newElement->next=list->head;
        //将新元素设置为列表头元素
        list->head=newElement;
    }else{
        //加入链表其他位置
        //如果当前元素的下一个元素是null则要追加的新元素就是链表的结尾元素
        if(element->next==NULL){
            list->tail=newElement;
        }
        //将元素中的下一个元素赋给新元素的下一个
        newElement->next=element->next;
        //将元素中的下一个指向新元素
        element->next=newElement;
    }
    //链表数量加1
    list->size++;
    return 0;
}
int linkedAppend(Linked * list,const void * data){
    Element * newElement;
    //分配内存给新的元素，如果失败则直接返回-1
    if((newElement=(Element *)malloc(sizeof(Element)))==NULL){
        return -1;
    }
    //插入新元素到Linked中
    newElement->data=data;
    if(getSize(list)==0){
        list->tail=newElement;
        newElement->next=NULL;
        list->head=newElement;
    }else{
        //将链表末尾的下一个元素指向新元素
        list->tail->next=newElement;
        //将链表的末尾更新为当前的新元素
        list->tail=newElement;
    }
    //链表数量加1
    list->size++;
    return 0;
}

int listRemove(Linked *list,Element * element,void * data){
    Element * oldElement;
    //不允许从空元素中移除
    if(getSize(list)==0){
        return -1;
    }
    //从链表中移除元素
    if (element==NULL) {
        //移除头元素
        data = list->head->data;
        oldElement=list->head;
        //将下一个元素指向头元素
        list->head=list->head->next;
    }else{
        if(element->next==NULL){
            return -1;
        }
        data=element->next->data;
        oldElement=element->next;
        element->next=element->next->next;
        if(element->next==NULL)
            list->tail=element;
    }
    free(oldElement);
    list->size--;
    return 0;
    
}




