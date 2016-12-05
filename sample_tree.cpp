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
    if(ch == '#'){
    	T=NULL;
    	//return T;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    //return T;//返回根节点
}
void createBiTree(BiTree &T)
{
    char data;
    data = getchar();
    if(data == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = data;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
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


//递归求深度
int depthtree(const BiTree & T)
{
	int left  = 0;
	int right = 0;
	if(T == NULL) return 0;

	left  = depthtree(T->lchild);
	right = depthtree(t->rchild);

	if(left > right)
		return ++left;
	else
		return ++right;
}

int main(){
    BiTree T;
    createBiTree(T);//建立
    PreOrderQuery(T);//输出
 	return 0;
}