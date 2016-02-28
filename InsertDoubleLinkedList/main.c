//
//  main.c
//  InsertDoubleLinkedList
//
//  Created by chenyufeng on 16/2/27.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  在双向非循环链表的某个pos位置插入一个值为x的节点

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化非循环双向链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//打印非循环双向链表,这个其实是正向打印
void printList(Node *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//创建非循环双向链表
Node *createList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {

        if (pNode == NULL) {
            //构造第一个节点
            pNode = pInsert;
            pMove = pNode;
        }else{

            //链接前后指针
            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        //为一个新节点分配空间
        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，建立链表成功\n",__FUNCTION__);

    return pNode;
}

//获取链表长度
elemType sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

Node *InsertList(Node *pNode,int pos,int x){

    int i = 1;
    int size = sizeList(pNode);
    Node *pMove;
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->next = NULL;
    pInsert->prior = NULL;

    pMove = pNode;

    //首先检查pos值是否合法
    if (pos < 0 || pos > size) {
        printf("%s函数执行，输入的pos值非法，插入节点失败\n",__FUNCTION__);
        return pNode;
    }

    //原链表是一个空链表，在第一个位置插入节点
    if (pNode == NULL && pos == 0) {
        pNode = pInsert;
        printf("%s函数执行，在pos=%d位置插入x=%d节点成功\n",__FUNCTION__,pos,x);
        return pNode;
    }

    //单独考虑插入到第一个节点和最后一个节点
    if (pos == 0) {
        //插入的节点作为第一个节点
        pInsert->next = pNode;
        pNode->prior = pInsert;
        pNode = pInsert;
    }else if(pos == size){
        //插入的节点是最后一个节点
        while (pMove->next != NULL) {
            pMove = pMove->next;
        }
        pMove->next = pInsert;
        pInsert->prior = pMove;
    }else{
        while (pMove != NULL) {
            if (i == pos) {

                //找到该位置，请注意下面的链表的链接顺序很重要
                pInsert->next = pMove->next;
                pMove->next->prior = pInsert;
                pInsert->prior = pMove;
                pMove->next = pInsert;
                break;
            }else{
                //继续找下一个节点
                i++;
                pMove = pMove->next;
            }
        }
    }

    printf("%s函数执行，在pos=%d位置插入x=%d节点成功\n",__FUNCTION__,pos,x);

    return pNode;
}

int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);

    pList = createList(pList);
    printList(pList);
    
    pList = InsertList(pList,3,999);
    printList(pList);
    
    return 0;
}








