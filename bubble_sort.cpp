/*************************************************************************
	> File Name: bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月23日 星期三 11时44分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

void bubble_sort(int *A,int len){
    bool isChange = false;
    for(int i=0;i<len;i++)
    {
        isChange = false;
        for(int j=i;j<len;j++)
        {
            if(A[j]>A[j+1])
            {
                isChange = true;
                int temp = A[j];
                A[j]   = A[j+1];
                A[j+1] = temp;   
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


