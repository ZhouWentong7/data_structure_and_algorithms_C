#include<stdio.h>
#include<stdlib.h> // 随机数生成
#include<time.h>

#define SIZE 10  // 定义数组大小
void output_list(int len, int a[]);
void linear_search(int a[],int t);
void binary_search1(int a[], int t); // [l,r]的范围内。
void binary_search2(int a[], int t);
void binary_search(int a[], int t);


int main(){
    int a[SIZE] = {0,1,2,3,4,5,6,7,8,9};

    int target;
    printf("Please input your target number(0~9):\n");
    scanf("%d", &target);

    printf("Original array:");
    output_list(SIZE, a);

    binary_search(a,target);
    return 0;

}

void output_list(int len, int a[])
{
    int i = 0;
    for(i ; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

void linear_search(int a[],int t)
{
    for(int i; i< SIZE; i++)
    {
        if(a[i] == t){
            printf("True");
            return;
        }
    }

    printf("False");

    return;
}

void binary_search1(int a[], int t)
{
    // 当 t 定义在全封闭[l,r]的范围内。

    int l,r,mid;
    l = 0; r = SIZE - 1; // 这里r注意
    

    // 因为left == right是有意义的
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(t < a[mid]){
            r = mid - 1;
        }
        else if(t > a[mid])
        {
            l = mid + 1;
        }
        else{
            printf("True.");
            return ;
        }

    }
    printf("False");
    return ;

}

void binary_search2(int a[], int t)
{
    // 当 t 定义在半关半开[l,r)的范围内。

    int l,r,mid;
    l = 0; r = SIZE; // 这里r注意
    

    // 因为left == right没有意义了
    while(l < r)
    {
        mid = l + ((r-l)>>1);

        if(t < a[mid]){
            r = mid;
        }
        else if(t > a[mid])
        {
            l = mid + 1;
        }
        else{
            printf("True.");
            return ;
        }

    }
    printf("False");
    return ;
}

//使用递归的二分法
void binary_search(int a[], int t){
    int flag = _binary_search(a,0,SIZE - 1,t);
    if(flag == 1){
        printf("True.\n");
    }
    if(flag == -1){
        printf("False.\n");

    }
}
int _binary_search(int a[], int l, int r, int t)
{
    if(r >= l)
    {
        int mid = (l + r) / 2;

        if( a[mid] == t)
            return 1;
        else if(a[mid] > t)
            return _binary_search(a,l,mid-1,t);
        else 
            return _binary_search(a, mid + 1, r, t);
        
    }
    return -1;
}



