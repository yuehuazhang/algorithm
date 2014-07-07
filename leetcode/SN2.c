/*******************************question********************************/
/*
    Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
 */

#include<stdio.h>
#include<malloc.h>
int SingleNumber(int* head, int n);

int main()
{
	int num;
	int *head;
	int i;

	printf("please input the number\n");
	scanf("%d", &num);
	printf("\nthe number is");
	
	head = (int*)malloc(sizeof(int)*num);

	for(i = 0; i < num; i++)
		scanf("%d", &head[i]);
	
	printf("%d", SingleNumber(head, num));
	
	return 0;
}

int SingleNumber(int* head, int n)
{
	int flag = 1;
	int one = 0, two = 0, three = 0;
	int i;

	for(i = 0; i < n; i++) {
		three = head[i]&two;		//存储出现三次的位
		two = two | (one&head[i]);	//此行结果为存储出现两次或三次的位
		one = one | head[i];		//存储包含一次、两次出现的位

		one = one & ~three;　　　　//将出现三次的位从one中删除
		two = two & ~three;　　　　//将出现三次的位从two中删除
	}
	return one;
}


