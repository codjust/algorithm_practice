/*************************************************************************
	> File Name: quicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月23日 星期三 10时54分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

void quicksort(int *A, int s,int t)
{
    if(s>t) return;

    int L = s;
    int R = t;
    int X = A[L];
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
    int a[5] = {2,4,1,7,3};
    quicksort(a,0,4);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
