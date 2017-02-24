Content
---------
* [快速排序](#快速排序)
* [冒泡排序](#冒泡排序)
* [插入排序](#插入排序)
* [选择排序](#选择排序)
* [二分法查找](#二分法查找)
* [简单树操作](#简单树操作)
* [简单socket例子](#简单socket例子)



###快速排序
------
```c++
/*************************************************************************
    > File Name: quicksort.cpp
    > Author:
    > Mail:
    > Created Time: 2016年11月23日 星期三 10时54分05秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int SelectMidValue(int *A, int low, int high)
{
    //三位取中
    int mid = low + (low + high)/2;
    if(A[mid] > A[high])
        swap(&mid, &high);
    else if(A[low] > A[high])
        swap(&low, &high);
    else if(A[mid]>A[low])
        swap(&mid, &low);
    return A[low];
}

void quicksort(int *A, int s,int t)
{
    if(s>t) return;

    int L = s;
    int R = t;
    int X = SelectMidValue(A, L, R);
    swap(A[L],X);//返回的值和最左边的数交换
    while(L<R)
    {
        while(L<R&&A[R]>X)
            R--;
        if(L<R)
        {
            A[L] = A[R];
            L++;
        }
        while(L<R&&A[L]<X)
            L++;
        if(L<R)
        {
            A[R] = A[L];
            R--;
        }
    }
    A[L] = X;
    quicksort(A,s,L-1);
    quicksort(A,L+1,t);
}

int main()
{
    int a[] = {2,4,1,7,3,0,5};
    quicksort(a,0,6);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}


```
###冒泡排序
--------
```c++
/*************************************************************************
    > File Name: bubble_sort.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年11月23日 星期三 11时44分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

void bubble_sort(int *A,int n){
    bool isChange = false;
    for(int i = 0;i < n; i++)
    {
        isChange = false;
        for(int j = i + 1;j < n; j++)
        {
            if(A[i]>A[j])
            {
                isChange = true;
                int temp = A[i];
                A[i]   = A[j];
                A[j] = temp;   
            }
        }
        if(!isChange)
            break;
    }
}


int main(){
    int a[5]={3,1,2,7,5};
    bubble_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
```

###插入排序
--------
```c++
/*************************************************************************
    > File Name: insertsort.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年11月23日 星期三 14时
