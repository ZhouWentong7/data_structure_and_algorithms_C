#include<stdio.h>
#include<stdbool.h> // 引入bool类型
#include<stdlib.h> // malloc() 和 free()

typedef struct _NODE
{
	int val;
	struct _NODE* next, *prev;
	
}NODE;

NODE *make_node(int v)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE*));
    newNode->val = v;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void trvl(NODE *h){
    if(NULL == h) return;
    for(NODE*i = h->next; i!=h;i = i->next){
        printf("%d ",i->val);
    }
    printf("\n");

    return;
}

bool search(int v, NODE* h)
{
    if(NULL == h) return false;
    for(NODE*i = h->next; i!=h;i = i->next){
        if(i->val == v)
            return true;
    }
    return false;
}

bool isEmpty(NODE * h){
    return false;
}

