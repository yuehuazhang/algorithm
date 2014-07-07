/*****************************************question********************************/
/*
    A linked list is given such that each node contains an additional random 
	pointer which could point to any node in the list or null.
	Return a deep copy of the list. 
   */

#include<stdio.h>
#include<malloc.h>

typedef struct node 
{
	struct node *next;
	struct node *random;
	int val;
} linknode;

void FreeList(linknode* head);
linknode* CopyRandomList(linknode* head);

int main()
{
	int n;
	int i;
	linknode *head, *temppoint;
	linknode *copyhead, *copyheadtemp;

	printf("please input the number the linknodes\n");
	scanf("%d", &n);

	printf("pease input the number of the val");

	head = (linknode*)malloc(sizeof(linknode));
	scanf("%d", &head->val);
	head->random = NULL;
	temppoint = head;
	for(i = 1; i < n; i++) {
		temppoint->next = (linknode*)malloc(sizeof(linknode));
		temppoint = temppoint->next;
		temppoint->random = NULL;
		scanf("%d", &temppoint->val);
	}
	temppoint->next = NULL;
	
	copyhead = CopyRandomList(head);
	copyheadtemp = copyhead;
	while(copyheadtemp != NULL) {
		printf("%d ", copyheadtemp->val);
		copyheadtemp = copyheadtemp->next;
	}

	FreeList(copyhead);
	FreeList(head);
}

linknode* CopyRandomList(linknode* head)
{
	linknode *temppoint, *temphead, *copyhead, *copytemphead;
	temphead = head;

	while(temphead != NULL) {
		temppoint = (linknode*)malloc(sizeof(linknode));
		temppoint->val = temphead->val;
		temppoint->next = temphead->next;
		temphead->next = temppoint;
		temphead = temppoint->next;
	}

	temphead = head;
	copyhead = head->next;
	copytemphead = head->next;
	while(temphead->next->next != NULL) { 
		if(temphead->random == NULL) 
			copytemphead->random = NULL;
		else copytemphead->random = temphead->random->next;
		temphead->next = copytemphead->next;
		copytemphead->next = copytemphead->next->next;
		temphead = temphead->next;
		copytemphead = copytemphead->next;
	}
	temphead->next = NULL;
	copytemphead->next = NULL;

	return copyhead;

}

void FreeList(linknode* head)
{
	linknode *point;
	point = head->next;
	while(head->next != NULL) {
		free(head);
		head = point;
		point = point->next;
	}
	free(head);
}
		
/*linknode* CopyRandomList_H(linknode* head, int n)
{
}
*/
