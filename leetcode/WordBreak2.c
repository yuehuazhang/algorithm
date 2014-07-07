/***************************************problem***************************************/
/*
    Given a string s and a dictionary of words dict, add spaces in s to construct 
	a sentence where each word is a valid dictionary word.

	Return all such possible sentences.

	For example, given
	s = "catsanddog",
	dict = ["cat", "cats", "and", "sand", "dog"].

	A solution is ["cats and dog", "cat sand dog"]. 
*/


#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAXSIZE 100

typedef struct {         //定义一个栈用来存放要输出的段
	int* point;
	int top;
}stack;                            

/*Out_put采用递归的算法，从s的最后一个位置开始用一个循环匹配从头到最后。其中如果一个位置i匹配成功则进行递归
  最后一个位置改为i-1进行递归，如果得到最后为零则结束递归，最终匹配成功，输出。
  */
void Out_path(int **path, char *s, int position, stack *stackp);

//打印s中begin到end之间的字符串
void Print(char *s, int begin, int end);

//比较s中begin到end之间的字符串和dict中的某个字符串是否相同
int Compare(char ** dict, int numdict, char* s, int begin, int end);

int main()
{
	char **dict;
	int**path;
	int numdict, nums;
	int i, j;
	char s[MAXSIZE];
	stack *stackp;
//	int begin, end;

	printf("please input the number of the dict\n");
	scanf("%d", &numdict); //字典词的数量

	dict = (char **)malloc(sizeof(char*)*(numdict));　//dict为指向字符数组的指针

	for(i = 0; i < numdict; i++) {
		dict[i] = (char*)malloc(sizeof(char)*MAXSIZE);
		scanf("%s", dict[i]);
	}
	printf("please input the s\n");
	scanf("%s", s);　　　　　　　　　　　　　　　　　　　//输入需要验证的字符串
/*	printf("please input the begin and end\n");
	scanf("%d", &begin);
	scanf("%d", &end);
	printf("%d", Compare(dict, numdict, s, begin, end));

*/
	nums = strlen(s);
	stackp = (stack*)malloc(sizeof(stack));
	stackp->top = 0;
	stackp->point = (int*)malloc(sizeof(int)*nums*2);

	path = (int**)malloc(sizeof(int*)*nums);
	
	for(i = 0; i < nums; i++) {
		path[i] = (int*)malloc(sizeof(int)*nums);
			memset(path[i], 0, sizeof(int)*nums);
	}

	for(i = 0; i < nums; i++)
		for(j = i; j < nums; j++)
			if(Compare(dict, numdict, s, i, j))
				path[i][j] = 1;
	
	Out_path(path, s, nums-1, stackp);
	
}

void Out_path(int **path, char *s, int position, stack *stackp)
{
	int i;
	if(position < 0) {
		for(i = stackp->top - 1; i > 0; i -= 2) {
			Print(s, stackp->point[i-1], stackp->point[i]);
		}

		printf("\n");
		return;
	}

	for(i = 0; i <= position; i++) {　//递归遍历
		if(path[i][position]) {
            stackp->point[stackp->top++] = i;
			stackp->point[stackp->top++] = position;
			Out_path(path, s, i-1, stackp);
			stackp->top -= 2;
		}
	}

	return;
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
	
void Print(char *s, int begin, int end)
{
	char a[MAXSIZE+1];
	int i, j = 0;
	for(i = begin; i <= end; i++)
		a[j++] = s[i];
	a[j] = '\0';
	printf("%s ", a);
}



