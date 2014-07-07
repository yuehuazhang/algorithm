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

linknode* Hascycle(linknode *);

int main()
{
	linknode* flag;
	int n = 10;
	int j = 0, i;
	int mid = 10;//循环的初始节点必须大于１主要用于测试

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
	point->next = midp;

	flag = Hascycle(head);
	printf("%d\n", flag->val);

	return 0;
}

linknode* Hascycle(linknode * head)
{
	linknode *slowp, *quickp, *midp, *tempp;

	int count = 0;
	int i;

	slowp = head;
	quickp = head;

	if(quickp->next != NULL) {	
		quickp = quickp->next->next;
		slowp = slowp->next;
	} 

	while(quickp != NULL && quickp->next != NULL) {
		if(quickp == slowp)
			break;
		quickp = quickp->next->next;
		slowp = slowp->next;
	}

	if(quickp == slowp) {
		quickp = quickp->next->next;
		slowp = slowp->next;
		count++;
		while(quickp != slowp) {
	       quickp = quickp->next->next;
	       slowp = slowp->next;
		   count++;
		}
		printf("%d\n", count);
		midp = tempp = head;
		while(1) {
			for(i = 0; i < count; i++)
				tempp = tempp->next;
			if(tempp == midp)
				return midp;
			else { 
				midp = midp->next;
				tempp = midp;
			}
		}
	}
	return NULL;
}
