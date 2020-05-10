#include "case.h"

struct ListNode{
	int value;
	ListNode *next;
	ListNode(int x) :value(x), next(NULL){}
};

ListNode* reverse_list(ListNode *head)
{
	ListNode *new_head = NULL;
	while (head){
		//1���ȼ�¼ԭʼhead��nextֵ
		ListNode *next = head->next;

		//2����head��nextָ��new_head
		head->next = new_head;

		//3����new_head�Ƶ���ǰ��
		new_head = head;

		//4��׼������ԭʼ����һ��nextֵ
		head = next;
	}
	return new_head;
}

int test_reverse_list()
{
	printf("------------hello, reverse_list start------------\n");
	ListNode a(10);
	ListNode b(20);
	ListNode c(30);
	ListNode d(40);
	ListNode e(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	ListNode * head = &a;
	while (head){
		printf("%d\n", head->value);
		head = head->next; 
	}
	printf("------------hello, reverse_list doing------------\n");
	ListNode * new_head = reverse_list(&a);

	while (new_head){
		printf("%d\n", new_head->value);
		new_head = new_head->next;
	}

	printf("------------hello, reverse_list  end------------\n");
	return 0;
}



