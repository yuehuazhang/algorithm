/***********************************question**********************************************/
/*
    Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

	You must do this in-place without altering the nodes' values
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node {
	struct node *next;
	int val;
}listnode;

listnode* Reorderlist(listnode* head);

int main()
{
	int num;
	int i;
	listnode *head, *point;

	printf("please input the number of shuzi\n");
	scanf("%d", &num);

	head = (listnode*)malloc(sizeof(listnode));
	scanf("%d", &head->val);
	point = head;
	for(i = 1; i < num; i++) {
		point->next = (listnode*)malloc(sizeof(listnode));
		point = point->next;
		scanf("%d", &point->val);
	}
	point->next = NULL;
	
	point = Reorderlist(head);
	
	while(point != NULL) {
		printf("%d", point->val);
		point = point->next;
	}

}

listnode* Reorderlist(listnode* head)
{
	listnode *end, *begin, *preend;
	
	 begin = head;

	if(head->next == NULL) 
		return head;
	
	while(begin->next != NULL) {
		end = begin->next;
		preend = begin;	
		while(end->next != NULL) {
			end = end->next;
			preend = preend->next;
		}
		if(begin->next == end)
			break;

		end->next = begin->next;
		begin->next = end;
		preend->next = NULL;
		begin = begin->next->next;
	}
	return head;
}




