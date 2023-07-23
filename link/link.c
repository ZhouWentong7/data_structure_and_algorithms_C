#include<stdio.h>
#include<stdbool.h> // 引入bool类型
#include<stdlib.h> // malloc() 和 free()

typedef struct _NODE
{
    /* data */
    int val; // 存储数据
    struct _NODE * next;// 指向下一个的指针
    
}NODE;

NODE* create_node(int v)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE)); //创建新的结构体对象
    newNode->val = v;   //初始化
    newNode->next = NULL;
    return newNode;
}

// 遍历链表
void trvl(NODE *h)
{
    for(NODE* i = h; i != NULL; i = i->next)
    {
        printf("%d ", i->val);
    }
    printf("\n");
    return;
}

// 查找链表中元素
bool search(NODE * h, int v)
{
    for(NODE* i = h; i != NULL; i = i->next)
    {
        if(i->val == v){
            return true;
        }
    }

    return false;
}

// 从头插入
NODE* insert_head(NODE *h, int v){
    NODE* newNode = create_node(v);
    newNode->val = v;
    newNode->next = h;
    return newNode;
}

// 删除值为v的节点
NODE* del(NODE* h, int v)
{
    NODE *p, *q;
    p = h, q = h;

    // 若头就是目标节点
    if(h->val == v){
        p = h->next;
        free(h);
        return p;
    }

    // 其余情况
    while(p->val != v)
    {
        q = p;// q记录要删掉的节点的前一个节点
        p = p->next;

        if(p == NULL){
            // check
            printf("This Node is not exist.\n");
            return h;
        }
    }
    
    // 此时p指向被删节点，q在前一个

    printf("The target number: %d, current Node: %d \n", v, p->val );
    
    // q->next指向被删节点的下一个节点，链接两部分。
    q->next = p->next;
    // 删除节点
    free(p);

    return h;
}

// 有序链表的插入

NODE* insert_ordered(NODE* h, int v)
{
    if (h == NULL){
        h = create_node(v);
        return;
    }
    // 若插入的梳子小于head，则作为新的头
    if(h->val >= v)
    {
        h = insert_head(h,v);
        return h;
    }

    // 一般情况
    NODE* p = h, *q = h;
    while(p->val < v){
        q = p;
        p = p->next;

        // 要插到尾巴,跳出循环
        if(p == NULL){
            break;
        }
    }

    NODE *newNode = create_node(v);
    q->next = newNode;
    newNode->next = p;

    return h;

}


// 反转链表

NODE *reverse(NODE* h){
    if(h->next == NULL){
        return h;
    }


    // p记录反转后的头
    // q源列表剩下的头
    // tmp 暂存源列表的下一个
    NODE *p, *q, *tmp;
    p = h; q = h->next;
    h->next = NULL;// head变成tail
    while(q){
        tmp = q->next; //剩下的头
        q->next = p;    // 
        p = q;
        q = tmp;
        
    }
    return p;
}

// 归并排序

NODE* merge(NODE *h1, NODE *h2)
{
    printf("START MERGE:\n");
    if (h1 == NULL) return h2;
	if (h2 == NULL) return h1;

    NODE* result, *p, *q;// p记录1，q记录2
    p = h1, q = h2;
    
    // 先确定头
    printf("SETTING HEAD.....\n");
    if(p->val < q->val){
        result = p;
        p = p->next;
    }else{
        result = q;
        q = q->next;
    }

    // body 这里都是result的尾插
    NODE *tail = result;
        printf("MERGING.....\n");

    
    while(p && q){

        if(p->val <= q->val){
            tail->next = p;
            p = p->next;
      
        }else{
            tail->next = q;
            q = q->next;

        }
        tail = tail->next;  
    }

    if(p){
        tail->next = p;
    }
    if(q){
        tail->next = q;
    }

    return result;
}



void test1(){
    NODE*h = NULL;
    h = insert_head(h,1);
    h = insert_head(h,42);
    h = insert_head(h,23);
    h = insert_head(h,34);
    h = insert_head(h,17);

    trvl(h);

    printf("DELETE 23\n");
    h = del(h,23);
    trvl(h);

    printf("DELETE 0\n");
    h = del(h,0);
    trvl(h);

    printf("DELETE 17\n");
    h = del(h,17);
    trvl(h);
    
    return;
}

void test2(){

    printf("INSERT IN ORDER\n");
    NODE*h = NULL;
    h = insert_ordered(h,1);
    h = insert_ordered(h,42);
    h = insert_ordered(h,23);
    h = insert_ordered(h,34);
    h = insert_ordered(h,17);

    trvl(h);
    return;
}

void test3(){
    printf("REVERSE THE LINK:\n");
    NODE*h = NULL;
    h = insert_ordered(h,1);
    h = insert_ordered(h,42);
    h = insert_ordered(h,23);
    h = insert_ordered(h,34);
    h = insert_ordered(h,17);

    h = reverse(h);

    trvl(h);

}

void test4(){
    printf("MERGE 2 LINKS:\n");
    NODE*h = NULL, *h1 = NULL;
    h = insert_ordered(h,1);
    h = insert_ordered(h,42);
    h = insert_ordered(h,23);
    h = insert_ordered(h,34);
    h = insert_ordered(h,17);
    printf("h:");
    trvl(h);
    h1 = insert_ordered(h1,3);
    h1 = insert_ordered(h1,24);
    h1 = insert_ordered(h1,32);
    h1 = insert_ordered(h1,44);
    h1 = insert_ordered(h1,71);
    printf("h1:");
    trvl(h1);
    NODE * m  = merge(h,h1);
    printf("AFTER:");
    trvl(m);
    return;
}


int main()
{
    test1();

    test2();
    test3();

    test4();
    return 0;
}
