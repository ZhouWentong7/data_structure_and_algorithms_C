#include<stdio.h>
#include<stdbool.h> // 引入bool类型
#include<stdlib.h> // malloc() 和 free()

typedef struct stack
{
    int *data;
    int top;
    int max_size;
}*stack;

void push(stack s, int val)
{
    if (s->top < s->max_size)
    {
        s->data[s->top++] = val;
    }
    return;
}

int pop(stack s)
{
    if(s->top > 0){
        return s->data[--s->top];
    }
}

// 销毁栈
void destroy_stack(stack s)
{
    free(s->data);
    free(s);
}

// create a stack
stack create_stack(int max_size)
{
    stack s = (stack)malloc(sizeof(struct stack));
    s->data = (int *)malloc(sizeof(int) * max_size);// 创建动态数组
    s->top = 0;
    s->max_size = max_size;
    return s;
}

int size(stack s)
{
    return s->top;
}

int isEmpty(stack s)
{
    return (s->top == 0);
}

int top(stack s)
{
    if(s->top > 0)
    {
        return s->data[s->top - 1];
    }
    return -1;
}

void test()
{
    stack s = create_stack(5); // 创建一个最大容量为5的栈

    printf("Is Empty?: %d", isEmpty(s));printf("\n");
    printf("Pushing elements into the stack: ");
    for (int i = 1; i <= 4; i++)
    {
        push(s, i);
        printf("%d ", i);
    }
    printf("\n");

    printf("Is Empty?: %d", isEmpty(s));  printf("\n");  
    printf("The top is: %d \n",top(s));
    printf("The size is: %d\n", size(s));

    
    printf("Popping elements from the stack: ");
    while (s->top > 0)
    {
        printf("%d ", pop(s));
    }
    printf("\n");

    destroy_stack(s); // 销毁栈
    return;
}

int main()
{
    test();
    return 0;
}