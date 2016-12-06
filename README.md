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

//递归求树的深度
int depthOfBiTree(const BiTree &T)
{
    int ldepth;
    int rdepth;

    if(T==NULL)//空树
        return 0;
    ldepth = depthOfBiTree(T->lchild);
    rdepth = depthOfBiTree(T->rchild);

    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);
}

//递归求二叉树的叶子结点个数  
int leafCountOfBiTree(const BiTree &T)  
{     
    if(T==NULL)  
        return 0;  
    if(T->lchild==NULL && T->rchild==NULL)  
        return 1;  
    return leafCountOfBiTree(T->lchild) + leafCountOfBiTree(T->rchild);  
}  

//交换二叉树的左右子女 
void exchangeChild(BiTree &T)  
{  
    if(T)  
    {  
        BiTree temp = NULL;  
          
        if(T->lchild ||T->rchild)  
        {  
            temp = T->lchild;  
            T->lchild = T->rchild;  
            T->rchild = temp;  
            exchangeChild(T->lchild);  
            exchangeChild(T->rchild);  
        }  
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
```c++
//翻转链表
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef ListNode struct ListNode;


ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while(pHead != NULL)
        {
            next = pHead->next;//save next
            pHead->next = pre;//->pre node
            pre = pHead;//pre == current
            pHead = next;//move head
        }  
       return pre;   
    }
```
归并排序
```c++
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
```

###简单socket例子

```c
//server 
/*************************************************************************
    > File Name: server.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年12月05日 星期一 17时30分35秒
 ************************************************************************/

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include <unistd.h>
using namespace std;

int main()
{
    int server_sockfd;//服务器套接字
    int client_sockfd;//接受的客户端套接字

    sockaddr_in my_addr;//服务端地址结构体
    sockaddr_in client_addr;//客户端地址结构体


    my_addr.sin_family = AF_INET;//设置IP通信
    my_addr.sin_addr.s_addr=INADDR_ANY;//允许任意链接到本地地址
    my_addr.sin_port = htons(9999);

    if((server_sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        cout<<"socket fd create failed!"<<endl;
        return 0;
    }

    int size = sizeof(my_addr);
    if(bind(server_sockfd,(struct sockaddr*)(&my_addr),size)<0)
    {
        cout<<"bind failed!";
        return 0;
    }

    listen(server_sockfd,5);//监听，队列长度为5
    cout<<"server listening...";
    socklen_t sin_len = sizeof(struct sockaddr);
    client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr,&sin_len);
    if(client_sockfd<0)
    {
        cout<<"accept failed.";
        return 0;
    }

    char buf[]="hello";
    size_t len = sizeof(buf);
    send(client_sockfd,buf,sizeof(buf),0);
    
    close(client_sockfd);
    close(server_sockfd);
    return 0;
}

```
```c
//client
/*************************************************************************
    > File Name: client.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年12月05日 星期一 18时32分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>

int main()
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd <0)
    {
        cout<<"socket created failed!";
        return 0;
    }

    sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port  = htons(9999);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int isConn = connect(sockfd,(struct sockaddr*)&client_addr,sizeof(client_addr));
    if(isConn<0)
    {
        cout<<"connect server failed.";
        return 0;
    }

    cout<<"connect to server:"<<endl;
    
    char buf[5];
    recv(sockfd,buf,5,0);
    printf("client recv:%s\n",buf);

    close(sockfd);

    return 0;
}

```


