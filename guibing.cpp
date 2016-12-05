#include <iostream>
using namespace std;

void Merge(int *a ,int left, int mid, int right, int * tmp);
void MergeSort(int *a, int left, int right, int * tmp);
void guibing(int *a, int len);
//归并排序
void guibing(int *a, int len)
{
	//使用一个临时数组
	int *temp = new int(len);
	MergeSort(a, 0, len-1, temp);
	delete []temp;
}

//先分解
void MergeSort(int *a, int left, int right, int * tmp)
{
	if(left < right) //递归出口
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid, tmp);
		MergeSort(a, mid+1, right, tmp);
		Merge(a, left, mid, right, tmp);
	}
}

//再合并
void Merge(int *a ,int left, int mid, int right, int * tmp)
{
	int i = left; int j = mid + 1;
	int n = mid;  int m = right;
	int k = 0;
	while(i<=n&&j<=m)
	{
		if(a[i]>a[j])
			tmp[k++] = a[j++];
		else
			tmp[k++] = a[i++];
	}

	while(i<=n) tmp[k++] = a[i++];
	while(j<=m) tmp[k++] = a[j++];

	for(int i=0;i<k;i++)
		a[left + i] = tmp[i];
}

int main()
{
	int a[] = {8,5,3,9,2,12};
	guibing(a, 6);
	for(int i=0;i<6;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}