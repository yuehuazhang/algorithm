/**********************************Max Points on a Line******************************/
/*
   Given n points on a 2D plane, find the maximum number of points that lie 
   on the same straight line.
   */

#include<stdio.h>
#include<malloc.h>

typedef struct {
	int x;
	int y;
} nodepoint;

void Mpoal(nodepoint*, int**, int );
int Maxelement(int **nump, int n);

int main()
{
	int n;
	nodepoint *point;
	int **nump;
	int i, j;

	printf("please input the number of the point");
	scanf("%d", &n);

	point = (nodepoint*)malloc(sizeof(nodepoint)*n);
	
	nump = (int**)malloc(sizeof(int*)*n);
	for(i = 0; i < n; i++)
		nump[i] = (int*)malloc(sizeof(int)*n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			nump[i][j] = 0;

	printf("please in put the zuo biao");
	for(i = 0; i < n; i++) 
		scanf("%d%d", &point[i].x, &point[i].y);
    
	Mpoal(point, nump, n);
	printf("%d", Maxelement(nump, n)+2);	
}

void Mpoal(nodepoint* point, int **nump, int n)
{
	int i, j, k;
	double temp1, temp2;
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			for(k = i + 1; k < n; k++) {
				temp1 = (point[i].x - point[j].x)*(point[k].y-point[j].y);
				temp2 = (point[i].y - point[j].y)*(point[k].x-point[j].x);
				if(temp1 == temp2) {
					nump[i][j]++;
					nump[k][i]++;
					nump[k][j]++;
				}
			}
}

int Maxelement(int **nump, int n)
{
	int i, j;
	int max = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			if(nump[i][j] > max)
				max = nump[i][j];
	return max;

}


