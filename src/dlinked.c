#include <stdlib.h>
#include <string.h>
#include "dlinked.h"

void dlinked_init(DLinked * list,void (*destory)(void *data)){
    list->size=0;
    list->head=NULL;
    list->tail=NULL;
    list->destory=destory;
}

void dlinked_destory(DLinked * list){
    void* data;
    while(getSize(list)>0){
        if(dlinked_remove(list,NULL,data)==0&&list->destory!=NULL){
            list->destory(data);
        }
    }
    memset(list,0,sizeof(DLinked));
}

int dlinked_add_next(DLinked * list,Node * node,const void * data){
    Node * newNode;
    if((newNode=(Node*)malloc(sizeof(Node)))!=NULL){
        return -1;
    }
    newNode->data=data;
    if(node==NULL){
        //如果是空链表则头就是尾
        if(getSize(list)==0){
            list->tail=newNode;
        }
        list->head=newNode;
        list->head->previous=NULL;
        list->head->next=NULL;
    }else{
        newNode->previous=node;
        if(node->next==NULL){
            //表示这是一个链表的末尾node
            list->tail=newNode;
        }
        newNode->next=node->next;
        node->next=newNode;
    }
    list->size++;
    return 1;
}

int dlinked_add_prev(DLinked * list,Node * node,const void * data){
    if(getSize(list)!=0&&node==NULL){
        return -1;
    }
    Node * newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return -1;
    }
    if(getSize(list)==0){
        //如果是空链表则添加到头部
        list->head=newNode;
        list->head->previous=NULL;
        list->head->next=NULL;
        list->tail=newNode;
    }else{
        newNode->previous=node->previous;
        newNode->next=node;
        if(node->previous=NULL){
            list->head=newNode;
        }else{
            node->previous->next=newNode;
        }
        node->previous=newNode;
    }
    list->size++;
    return 1;
}