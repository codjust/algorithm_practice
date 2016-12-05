//翻转链表
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef ListNode struct ListNode;


ListNode* ReverseList(ListNode* head)
{
	ListNode* a = NULL;
	ListNode* b = NULL;
	if(head == NULL) return NULL;

	a = head->next;//第一个节点
	while(a->next != NULL)
	{
		b = a->next;//第二个节点
		a->next = b->next;//第一个指向第三个
		b->next = head->next;//第二个指向第一个
		head->next = b;//头指针指向第二个，因为这个时候第二个到头节点了
	}

	return head;
}