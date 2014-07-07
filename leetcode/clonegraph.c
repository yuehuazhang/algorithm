/************************************question**********************************************/
/*
   Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 
   */

#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node {
	int label;
	struct node **neighbor;
} graphnode;

typedef struct qnode {
	graphnode** array;
	int rear;
	int front;
} queue;

typedef struct hash {
	graphnode* pnode;
	int flag;
}hashnode;

//求邻居节点个数的函数
int GetNeighbor(graphnode*);

graphnode* CloneGraph(graphnode* graph, int n);

graphnode* CloneGraph(graphnode* graph, int n)
{
	int k;
	int i;
	hashnode *hashtab;
	graphnode *ograph, *cgraph, *copygraph;

//构造简化的hash表用来判断标记节点是否已经分配内存，如果已分配内存则记下地址
	hashtab =(hashnode*)malloc(sizeof(hashnode)*n);
//初始化为０表示标记未分配内存，为１表示标记已分配内存
	for(i = 0; i < n; i++)
		hashtab[i].flag = 0;      

//构建队列用于广度优先遍历，队列中存储节点的地址
	queue *graphqueue = (queue*)malloc(sizeof(queue));
	graphqueue->front = 0;
	graphqueue->rear = 0;
	graphqueue->array = (graphnode**)malloc(sizeof(graphnode*)*n);

	if(!graph)
		return NULL;

	copygraph = (graphnode*)malloc(sizeof(graphnode));//图的头节点
	copygraph->label = graph->label;
	graphqueue->array[0] = graph;
	graphqueue->front++;
	cgraph = copygraph;
	hashtab[graph->label].flag = 1;
	hashtab[graph->label].pnode = copygraph;


	while(graphqueue->front != graphqueue->rear) {
		ograph = graphqueue->array[graphqueue->rear++];
		k = GetNeighbor(ograph);
		cgraph = hashtab[ograph->label].pnode;
		cgraph->neighbor = (graphnode**)malloc(sizeof(graphnode*) *(k+1));
		for(i = 0; i < k; i++) {
			if(hashtab[ograph->neighbor[i]->label].flag == 0) {
					cgraph->neighbor[i] =  (graphnode*)malloc(sizeof(graphnode));
					cgraph->neighbor[i]->label = ograph->neighbor[i]->label;
					hashtab[ograph->neighbor[i]->label].flag = 1;
					hashtab[ograph->neighbor[i]->label].pnode = cgraph->neighbor[i];
					graphqueue->array[graphqueue->front++] = ograph->neighbor[i];
			} else
				    cgraph->neighbor[i] = hashtab[ograph->neighbor[i]->label].pnode;
		}
		cgraph->neighbor[i] = NULL;
	}
    free(graphqueue->array);
	free(graphqueue);
	free(hashtab);
	return copygraph;
}
				
int GetNeighbor(graphnode* point)
{
	int i = 0;
	int num = 0;

	for(;point->neighbor[i] != NULL; i++)
		num++;
	return num;
}

int main()
{
	int i;
	graphnode* copygraph;
	graphnode *examplegraph = (graphnode*)malloc(sizeof(graphnode));
	examplegraph->label = 0;
	examplegraph->neighbor = (graphnode**)malloc(sizeof(graphnode*) *3);
	for(i = 0; i < 2; i++) {
		examplegraph->neighbor[i] = (graphnode*)malloc(sizeof(graphnode));
		examplegraph->neighbor[i]->label = i + 1; 
	}
	examplegraph->neighbor[i] = NULL;

	examplegraph->neighbor[0]->neighbor = (graphnode**)malloc(sizeof(graphnode*) *2);
	examplegraph->neighbor[0]->neighbor[0] = examplegraph;
	examplegraph->neighbor[0]->neighbor[1] = NULL;
	
	examplegraph->neighbor[1]->neighbor = (graphnode**)malloc(sizeof(graphnode*) *2);
	examplegraph->neighbor[1]->neighbor[0] = examplegraph;
	examplegraph->neighbor[1]->neighbor[1] = NULL;
	
	copygraph = CloneGraph(examplegraph ,3);
	printf("%d", copygraph->neighbor[0]->neighbor[0]->label);
}



	

