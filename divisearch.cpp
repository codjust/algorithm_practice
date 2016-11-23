/*************************************************************************
	> File Name: divisearch.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月23日 星期三 14时58分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool divisearch(int *A,int len,int key){
    int start = 0;
    int end  = len-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(A[mid]>key){
            end=mid-1;
        }else if(A[mid]<key){
            start=mid+1;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    int a[]={3,5,7,9,12};
    bool flag = divisearch(a,5,5);
    if(flag)
        cout<<"find it";
    else
        cout<<"not found";
    
    flag = divisearch(a,5,2);
    if(flag)
          cout<<"find it";
    else
    cout<<"not found";
}
