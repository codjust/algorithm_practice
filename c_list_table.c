/*************************************************************************
	> File Name: c_list_table.c
	> Author: 
	> Mail: 
	> Created Time: 2016年12月05日 星期一 09时58分42秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef struct Node ListNode;
struct Node {
    int data;
    ListNode *next;
};

ListNode* initList(){
    ListNode *list = NULL;
    list = (ListNode*)malloc(sizeof(ListNode));
    if(list == NULL)
    {
        printf("create list failed!")
        return NULL;
    }
    list->next = NULL;
}

int insertlist(ListNode*list, int num)
{
    if(list == NULL) return -1;

    //假设按大小插入
    ListNode* node = initList();
    if(node == NULL) return -1;
    node->data = num;
    while(list->next&&num > list->next->data)
        list = list->next;
    //找到待插入的位置
    if(list->next == NULL)
    {
        list->next = node;
    }else{
        node->next=list->next;
        list->next=node;
    }
    return 0;
}

void deletenode(ListNode* list, int num)
{
    if(list == NULL) return;
    while(list->next&&list->data == num)
        list = list->next;
    if(list->next == NULL)
    {}
}



int main()
{

    return 0;
}


