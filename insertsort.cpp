/*************************************************************************
	> File Name: insertsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月23日 星期三 14时35分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

void insertsort(int *A,int len)
{
    int j,temp;
    for(int i=1;i<len;i++){
        j=i;
        temp=A[i];//save current value 
        while(j>0&&temp<A[j-1]){
            A[j]=A[j-1];//move forward 
            j--;
        }
        A[j]=temp;//insert value 
    }
}
int main()
{
    int a[]={2,1,4,5,9};
    insertsort(a,5);
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
