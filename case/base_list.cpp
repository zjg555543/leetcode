#include "base_list.h"


struct ListNode{
	int value;
	ListNode *next;
};

int base_list()
{
	printf("------------hello, base_list start------------\n");
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;
	a.value = 10;
	a.next = &b;
	b.value = 20;
	b.next = &c;
	c.value = 30;
	c.next = &d;
	d.value = 40;
	d.next = &e;
	e.value = 50;
	e.next = NULL;

	ListNode * head = &a;
	while (head){
		printf("%d\n", head->value);
		head = head->next; 
	}


	printf("------------hello, base_list  end------------\n");
	return 0;
}

