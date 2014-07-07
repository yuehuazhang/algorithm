/**************************************question***********************************************/
/*
   here are N children standing in a line. Each child is assigned a rating value.

   You are giving candies to these children subjected to the following requirements:

       Each child must have at least one candy.
	       Children with a higher rating get more candies than their neighbors.

		   What is the minimum candies you must give? 
   */
/***************************************solution**********************************************/
/*
   解决方案分两部分，首先最左边数组元素赋值为１然后从左向右遍历数组如果右边大于左边那么右边等于
   左边加一。否则也赋值为零，这样可以得到满足比率右大于左时所分candy也右大于左，并且是这种条件
   下的每个人得到的最小值。其次从右向左遍历若左大于右则左边分的为右边值加一，最后这样可以得到
   满足比率左大于右时所分candy也左大于右且是最小的糖果数，我们要求两条件同时成立，那么每个人得到
   的是从左往右与从右往左的最大值
   */

#include<stdio.h>
#include<malloc.h>
#include<string.h>

int Candy(int *, int);

int main()
{
	int n;
	int *pchild;
	int i;

	printf("please input the number of the child\n");
	scanf("%d", &n);

	pchild = (int*)malloc(sizeof(int)*n);

	printf("please input the rate\n");

	for(i = 0; i < n; i++)
		scanf("%d", &pchild[i]);
	printf("the sum is %d\n", Candy(pchild, n));
}

int Candy(int *pchild, int n)
{
	int i;
	int sum = 0;

	int *temp1 = (int*)malloc(sizeof(int)*n);
	int *temp2 = (int*)malloc(sizeof(int)*n);
	memset(temp1, 0, sizeof(int)*n);
	memset(temp2, 0, sizeof(int)*n);
	
	temp1[0] = 1;
	for(i = 0; i < n - 1; i++) {
		if(pchild[i+1] > pchild[i])
			temp1[i+1] = temp1[i] + 1;
		else temp1[i+1] = 1;
	}

	temp2[n-1] = 1;
	for(i = n - 1; i > 0; i--) {
		if(pchild[i] < pchild[i-1]) 
			temp2[i-1] = temp2[i] + 1;
		else temp2[i-1] = 1;
	}

	printf("the number of cnady that every child gets is ");
	for(i = 0; i < n; i++) {
		if(temp1[i] > temp2[i]) {
			sum += temp1[i];
			printf("%d ", temp1[i]);
		} else {
			sum += temp2[i];
			printf("%d ", temp2[i]);
		}
	}
		printf("\n");
		return sum;
}
	


			
			









