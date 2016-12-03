Content
---------
* [快速排序](#快速排序)
* [冒泡排序](#冒泡排序)
* [插入排序](#插入排序)
* [选择排序](#选择排序)
* [二分法查找](#二分法查找)
* [简单树操作](#简单树操作)



###快速排序
------
```c++
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
```

###插入排序
--------
```c++
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
```

###选择排序
--------
```c++
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
```

###二分法查找
--------
```c++
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
```

###简单树操作
--------
```c++
//有点小问题
#include <iostream>
#include <malloc.h>
#include <stack>
#include <queue>
using namespace std;

//tree struct
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//先序建立二叉树
BiTree CreateBiTree(){
    char ch;
    BiTree T;
    scanf("%c",&ch);
    if(ch=='#')T=NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;//返回根节点
}
// 先序遍历
void PreOrderQuery(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrderQuery(T->lchild);
        PreOrderQuery(T->rchild);
    }
}
//中序遍历
void MidPreOrderQuery(BiTree T){
    if(T){
        PreOrderQuery(T->lchild);
        cout<<T->data<<" ";
        PreOrderQuery(T->rchild);
    }
}

//后序遍历
void LastPreOrderQuery(BiTree T){
    if(T){
        PreOrderQuery(T->lchild);
        PreOrderQuery(T->rchild);
        cout<<T->data<<" ";
    }
}

//深度优先遍历
void DepthFirstTravel(BiTree root){
    stack<BiTree> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
        if(root->rchild != NULL)
        {
            s.push(root->rchild);
        }
        if(root->lchild != NULL)
        {
            s.push(root->lchild);
        }
    }
}

//广度优先遍历
void BreadthFurstTraveal(BiTree root)
{
    queue<BiTree> q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        cout<<root->data<<" ";
        q.pop();
        if(root->lchild!=NULL)
            q.push(root->lchild);
        if(root->rchild!=NULL)
            q.push(root->rchild);
    }
}

int main(){
    BiTree T;
    T = CreateBiTree();//建立
    PreOrderQuery(T);//输出
    return 0;
}

```
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
```c++
bool Find(int target, vector<vector<int> > array) {
            int row = array.size();
            int col = array[0].size();
            //从左下角开始
            int y = 0;
            int x = row-1;
            while(y <= col-1 && x >=0)
    {
                    if( target < array[x][y] )
                        x--;
                    else if( target > array[x][y] )
                        y++;
                    else
                        return true;
                
    }
            return false;
        
}
```



