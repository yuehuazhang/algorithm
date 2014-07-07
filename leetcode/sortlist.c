/***************************question************************************/
/*Sort a linked list in O(n log n) time using constant space complexity*/
/****************************solution***********************************/
/*  1、归并排序
　* 2、寻找中间元素
　* 3、链表的合并
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int val;
	struct node *next;
}linknode;

linknode* Mergelist(linknode* list1, linknode* list2);//两个链表的合并
linknode* Sortlist(linknode* list);//归并排序
linknode* Getmid(linknode* list);//寻找中间点

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
	p = Sortlist(point);

	while(p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}

	return 0;
}

linknode* Mergelist(linknode* list1, linknode* list2)//合并
{
	linknode *list, *head;
	linknode *p1, *p2;
	
	if(list1->val < list2->val) {
			list = list1;
			head = list1;
			list1 = list1->next;
		} else	{
			list = list2;
			head =list2;
			list2 = list2->next;
		}

	while(list1 && list2) {
		if(list1->val < list2->val) {
			list ->next = list1;
			list1 = list1->next;
			list = list->next;
		} else	{
			list->next = list2;
			list2 = list2->next;
			list = list->next;
		}
	}
	if(list1 != NULL)
		list->next = list1;
	if(list2 != NULL)
		list->next = list2;
	return head;
}

linknode* Getmid(linknode* list)//寻找中间值
{
	linknode* p;
	if(list == NULL)
		return NULL;
	if(list->next == NULL)
		return list;
	linknode *mid, *fast;
	fast = mid = list;

	while(fast && fast->next) {
		p = mid;
		mid = mid->next;
		fast = fast->next->next;
	}
	p->next = NULL;
	return mid;
}

linknode* Sortlist(linknode* list) // 递归排序
{
	linknode *p;
	if((p = Getmid(list)) != NULL && p != list)
	return Mergelist(Sortlist(p), Sortlist(list));
	else if(p == list)
		return list;
	else return NULL;
}



	

