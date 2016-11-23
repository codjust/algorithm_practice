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