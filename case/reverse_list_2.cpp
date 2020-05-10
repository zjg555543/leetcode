#include "case.h"

struct ListNode{
	int value;
	ListNode *next;
	ListNode(int x) :value(x), next(NULL){}
};
ListNode* reverse_list_between(ListNode *head, int m, int n)
{
	ListNode *part_new_head = NULL;
	ListNode *first_node = head;
	ListNode *pre_node_m = NULL;
	ListNode *node_m = NULL;
	ListNode *next_node_n = NULL;
	ListNode *node_n = NULL;
	int i = 1;
	while (head){
		//0、保存next值，防止后续被修改
		ListNode * next = head->next;
		//1、记录m前一个值
		if (i == (m-1)){
			pre_node_m = head;
		}

		//2、记录m的值
		if (i == m){
			node_m = head;
		}

		//3、记录n的值
		if (i == n){
			node_n = head;
		}

		//4、记录n+1的值
		if (i == n + 1){
			next_node_n = head;
		}

		//5、倒叙m-n之间的值
		if (i >= m && i <= n){
			head->next = part_new_head;
			part_new_head = head;
		}

		//遍历下一个
		i++;
		head = next;
	}

	if (pre_node_m != NULL){
		pre_node_m->next = part_new_head;
	}
	else{
		first_node = node_n;
	}
		
	node_m->next = next_node_n;

	return first_node;
}

int test_reverse_list_between()
{
	printf("------------hello, reverse_list start------------\n");
	{
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
		ListNode * new_head = reverse_list_between(&a, 2, 4);

		while (new_head){
			printf("%d\n", new_head->value);
			new_head = new_head->next;
		}
	}
	{
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
		printf("------------hello, reverse_list doing------------\n");
		ListNode *new_head = reverse_list_between(&a, 3, 4);

		while (new_head){
			printf("%d\n", new_head->value);
			new_head = new_head->next;
		}
	}
	
	{
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
		printf("------------hello, reverse_list doing------------\n");
		ListNode *new_head = reverse_list_between(&a, 1, 5);

		while (new_head){
			printf("%d\n", new_head->value);
			new_head = new_head->next;
		}
	}

	printf("------------hello, reverse_list  end------------\n");
	return 0;
}



