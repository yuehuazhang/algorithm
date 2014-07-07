/***************************问题***************************************/
/*
    Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?    
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int val;
	struct node *next;
} linknode;

int Hascycle(linknode *);

int main()
{
	int flag;
	int n = 10;
	int j, i;
	int mid = 3;//循环的初始节点

	linknode *point, *head, *midp;
	head = (linknode*)malloc(sizeof(linknode));
	head->val = j++;
	point = head;

	for(i = 1; i < mid; i++) {
	    point->next = (linknode*)malloc(sizeof(linknode));
	    point = point->next;
    	point->val = j++;
	}
	midp = point;
	for(i = mid; i < n; i++) {
	    point->next = (linknode*)malloc(sizeof(linknode));
		point = point->next;
		point->val = j++;
	}
	point->next = NULL;

	flag = Hascycle(head);
	printf("%d\n", flag);

	return 0;
}

int Hascycle(linknode * head)
{
	linknode *slowp, *quickp;
	slowp = head;
	quickp = head;

	if(quickp->next != NULL) {	
		quickp = quickp->next->next;
		slowp = slowp->next;
	} 

	while(quickp != NULL && quickp->next != NULL) {
		if(quickp == slowp)
			return 1;
		quickp = quickp->next->next;
		slowp = slowp->next;
	}

	return 0;
}
