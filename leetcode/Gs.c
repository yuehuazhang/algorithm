/*********************************problem********************************************/
/*
    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
	its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

	Note:
	The solution is guaranteed to be unique. 
   */

/*************************************solution**********************************************/
/*
如果所有站的代价和大于0，则所求的路线必定存在。如果总代价〉=0,从序号0开始求代价和，如果代价和小于0，
则不是从本站或者本站之前的某一个代价大于0的站开始，必从下一站即之后的站开始，而且这样的站必定存在O(n)。
   */
#include<stdio.h>
#include<malloc.h>

int CanCompleteCycle(int* gas, int *cost, int n);

int main()
{
	int n;
	int i;

	int *gas, *cost;

	printf("please input the number of gasstation\n");
	scanf("%d", &n);

	gas = (int*)malloc(sizeof(int)*n);
	cost = (int*)malloc(sizeof(int)*n);
	
	printf("please input the gas of station\n");
	for(i = 0; i < n; i++)
		scanf("%d", &gas[i]);

	printf("please input the cost of the station\n");
	for(i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	printf("%d", CanCompleteCycle( gas, cost, n));
}

CanCompleteCycle(int* gas, int *cost, int n)
{
	int i;
	int start;
	int sum = 0, total = 0;
	
	start = i = 0;
	for(; i < n; i++) {
		sum  += gas[i] - cost[i];
		total += gas[i] - cost[i]; 
		if(sum < 0) {
			start = i + 1;
			sum = 0;
		}
	}

	if(total < 0) 
		return -1;
	else return start;
}



