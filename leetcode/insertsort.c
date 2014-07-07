/***********************************Insertion Sort List***************************************/
/*
   Sort a linked list using insertion sort.
   */

#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int val;
	struct node *next;
}linknode;

linknode* Insertsort(linknode* list);

int main()
{
	int n; 
	int i;
	linknode *point, *p;

	printf("please input the number of the point\n");
	scanf("%d", &n);
	
	point = (linknode*)malloc(sizeof(linknode));
	p = point;
	scanf("%d", &p->val);
	for(i = 1; i < n; i++) {
		p->next = (linknode*)malloc(sizeof(linknode));
		p = p->next;
		scanf("%d", &(p->val));
	}
	p->next = NULL;

	p = Insertsort(point);

	while(p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	return 0;
}

linknode* Insertsort(linknode* list)
{
	linknode* temp, *tempscan, *head, *tempfront1, *tempfront2;
	head = (linknode*)malloc(sizeof(linknode));
	head->next = list;
	tempfront1 = head;
	tempscan = list;
	temp = list->next;
	tempfront2 = list;

	while(temp) {
		while(tempscan->val < temp->val  && temp != tempscan) {
			tempfront1 = tempscan;
			tempscan = tempscan->next;
		}
		if(tempscan->val > temp->val) {	
			tempfront2->next = temp->next;
			tempfront1->next = temp;
			temp->next = tempscan;
		}
		tempscan = head->next;
		temp = tempfront2->next;
		tempfront1 = head; 
	}

	temp = head->next;
	free(head);
	return temp;
}


