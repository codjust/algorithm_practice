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

  //  cout<<A[mid]<<" "<<A[low]<<" "<<A[high]<<endl;
    return A[low];
}

void quicksort(int *A, int s,int t)
{
    if(s>t) return;

    int L = s;
    int R = t;
    int X = SelectMidValue(A, L, R);
  //  cout<<"X->:"<<X<<endl;
    swap(A[L],X);//返回的值和最左边的数交换
  //  cout<<"A[L]->:"<<A[L]<<endl;
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
    // int x=2;
    // int y=3;
    // swap(&x, &y);
    // cout<<x<<" "<<y<<endl;
    int a[] = {2,4,1,7,3,0,5};

   // cout<<"address:"<<a[0]<<" "<<&a[0]<<endl;
    quicksort(a,0,6);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
