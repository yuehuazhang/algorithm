/************************************question***************************************/
/*
    Given an input string, reverse the string word by word.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the". 
*/
/*********************************Clarification************************************/
/*
    What constitutes a word?
	A sequence of non-space characters constitutes a word.
	Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.
	How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

void reverse(char a[]);

int main()
{
	int i = 0;
	char c;
	char str[1024];
	while((c = getchar()) != '\n')
		str[i++] = c;
	str[i] = '\0'; 
	reverse(str);
}

void reverse(char str[])
{
	char strtemp[1024];
	int i = 0;

	strcpy(strtemp, str);

	while(strtemp[i] != '\0') {
		if(strtemp[i] == ' ') {
			strtemp[i] = '\0';
			i++;
			continue;
		} else i++;
	}
	
	i--;
	while(i >= 0) {
		if(strtemp[i] == '\0' && strtemp[i+1] != '\0')
			printf("%s ", &strtemp[i+1]);
		i--;
	}
	printf("%s", &strtemp[0]);
}
