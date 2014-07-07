/********************************Evaluate Reverse Polish Notation************************/
/*
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
	Valid operators are +, -, *, /. Each operand may be an integer or another expression.
   */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100];
	char str[10];
	int point = 0;
	int operator1, operator2;
	scanf("%s", str);
	while(str[0] != ']') {
		if(str[0] != '+' && str[0] != '-' && str[0] != '*' &&  str[0] != '/' && str[0] != '[')
		a[point++]=atoi(str);
		else if(str[0] == '+') {
			operator1 = a[point-2];
			operator2 = a[point-1];
			point -= 2; 
			a[point++] = operator1 + operator2;
		} else if(str[0] == '-') {
			operator1 = a[point-2];
			operator2 = a[point-1];
			point -= 2; 
			a[point++] = operator1 - operator2;
		} else if(str[0] == '*') {
			operator1 = a[point-2];
			operator2 = a[point-1];
			point -= 2; 
			a[point++] = operator1 * operator2;
		}else if(str[0] == '/') {
			operator1 = a[point-2];
			operator2 = a[point-1];
			point -= 2; 
			a[point++] = operator1 / operator2;
		}
		scanf("%s", str);
	}
	printf("%d", a[0]);
	return 0;
}

		



