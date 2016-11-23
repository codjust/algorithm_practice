// 还是先来看看选择排序的思想。选择排序的思想非常直接，不是要排序么？
// 那好，我就从所有序列中先找到最小的，然后放到第一个位置。
// 之后再看剩余元素中最小的，放到第二个位置……以此类推

#include <iostream>
using namespace std;

void selectsort(int *A,int len)
{
	for(int i=0;i<len;i++)
	{
		int min   = A[i];
		int index = i;
		for(int j=i+1;j<len;j++)
		{
			if(A[j]<min)
			{
				min=A[j];
				index=j;
			}
		}
		int temp = A[i];
		A[i]     = min;
		A[index] = temp;
	}
}

int main()
{
	int a[]={2,4,6,1,9};
	selectsort(a,5);
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}