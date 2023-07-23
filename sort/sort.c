#include<stdio.h>
#include<stdlib.h> // 随机数生成
#include<time.h>

#define SIZE 10  // 定义数组大小


void print_array(int a[])
{
    int i = 0;
    while(i<SIZE)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
}

void bubble_sort(int nums[])
{
    printf("-------- Bubble_Sort ----------\n");
    int i, j,tmp;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 1; j< SIZE- i ; j++)
        {
            if(nums[j] < nums[j-1])
            {
                tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
        }

        printf("bubble loop %d: ",i);
        print_array(nums);
    }

    printf("END:");
    print_array(nums);
    printf("==================================\n");
}

void bubble_sort_optimized(int nums[])
{
     printf("-------- Bubble_Sort_Optimized ----------\n");
    int j,tmp,last,cnt;
    last = SIZE-1; // last will remember the last time where the swap happened.
    cnt = 0;
    while(last)
    {
        last = 0; // Ever time reset to 0 because we start from the first position.


        for(j = 1; j < SIZE; j++)
        {
            if(nums[j] < nums[j-1])
            {
                tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;

                last = j-1;
                printf("last = %d; ",last);
            }
        }

        printf("\nbubble loop %d: ",cnt);
        print_array(nums);
    }
    printf("END:");
    print_array(nums);
    printf("==================================\n");

}


int main()
{
    int a[SIZE] = {3,6,2,7,9,8,0,1,5,4};
    printf("The original array: ");
    print_array(a);

    bubble_sort(a);
    int b[SIZE] = {3,6,2,7,9,8,0,1,5,4};
    bubble_sort_optimized(b);

    return 0;

}