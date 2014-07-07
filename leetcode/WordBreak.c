/**********************************problem**************************************************/
/*
    Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

	For example, given
	s = "leetcode",
	dict = ["leet", "code"].

	Return true because "leetcode" can be segmented as "leet code". 
   */
/*******************************************solution******************************************/
/*
    运用DP算法，建立一个s长的数组，我们知道对于任意的一个前k个匹配必然是在k前面有一个i是匹配的
	同时i到k之间在dict中存在。这样我们可以一直推导到最后一个strlen(s);
   */

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAXSIZE 100

int WorkBreak(char**, char*, int);

int main()
{
	char **dict;
	int numdict;
	int i;
	char s[MAXSIZE];
//	int begin, end;

	printf("please input the number of the dict\n");
	scanf("%d", &numdict);

	dict = (char **)malloc(sizeof(char*)*(numdict));

	for(i = 0; i < numdict; i++) {
		dict[i] = (char*)malloc(sizeof(char)*MAXSIZE);
		scanf("%s", dict[i]);
	}
	printf("please input the s\n");
	scanf("%s", s);
/*	printf("please input the begin and end\n");
	scanf("%d", &begin);
	scanf("%d", &end);
	printf("%d", Compare(dict, numdict, s, begin, end));

*/
	printf("%d", WorkBreak(dict, s, numdict));
}

int WorkBreak(char** dict, char* s, int numdict)
{
	int i, j;
	int * segp;
	int num;

	num = strlen(s);
	segp = (int*)malloc(sizeof(int)*num);
	memset(segp, 0, sizeof(int)*num);

	for(i = 0; i < num; i++) 
		for(j = 0; j < i; j++) {
			if((( segp[j] > 0) && Compare(dict, numdict, s, j + 1, i)) || (j == 0 && Compare(dict, numdict, s, j, i))) {
				segp[i] = 1;
				break;
			}
		}
	return segp[num-1];
}

int Compare(char ** dict, int numdict, char* s, int begin, int end)
{
	int i;
	int temp = end - begin + 1;
	int temp1;
	char *pointd, *points;
	
	for(i = 0; i < numdict; i++) {
		pointd = dict[i];
	    points = &s[begin];
		temp1 = temp;
		while(*pointd == *points && (temp1 > 0)) {
			pointd++;
			points++;
			temp1--;
		}
		if(temp1 <= 0 && *pointd == '\0')
			return 1;
	}
	return 0;
}
	

