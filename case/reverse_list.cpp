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
		//1、先记录原始head的next值
		ListNode *next = head->next;

		//2、把head的next指向new_head
		head->next = new_head;

		//3、把new_head移到最前端
		new_head = head;

		//4、准备遍历原始的下一个next值
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



