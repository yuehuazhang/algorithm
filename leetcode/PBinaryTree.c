/******************************************** 问题**************************************/
/*Given a binary tree, return the preorder traversal of its nodes' values.*************/
/************************非递归的解法思路***********************************************/
/*　　１、首先后续遍历的顺序是左右中
	　２、我们必然需要一个栈
	　３、首先遍历左子树，将经过的每一个节点都压入栈中直到叶子节点
	　４、输出叶子节点从栈中弹出一个元素
	　５、判断刚才输出的是右子树的点或右子树为ＮＵＬＬ如果是则输出此节点同时弹出一个元素
	　否则遍历弹出元素的右子树遍历同３。
	　６、当整个栈为空时结束
 */
#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}treenode;

void Preorder_R(treenode * treehead);
void Preorder(treenode * treehead);

int main()
{

	treenode *treehead, *tnode;
	
/*	treehead = (treenode*)malloc(sizeof(treenode));
	treehead->val = 1;
	treehead->left = treehead->right = NULL;

	treehead->right = (treenode*)malloc(sizeof(treenode));
	tnode = treehead->right;
	tnode->val = 2;
	tnode->left = tnode->right = NULL;

	tnode->left = (treenode*)malloc(sizeof(treenode));
	tnode = tnode->left;
	tnode->val = 3;
	tnode->left = tnode->right = NULL;
*/	//Postorder_R(treehead);
	treehead = (treenode*)malloc(sizeof(treenode));
	treehead->val = 1;
	treehead->left = treehead->right = NULL;
	tnode = treehead;

	tnode->left = (treenode*)malloc(sizeof(treenode));
	tnode->left->val = 2;

	tnode->right = (treenode*)malloc(sizeof(treenode));
	tnode->right->val = 3;
	tnode->right->left = tnode->right->right = NULL;
	
	tnode = tnode->left;
	tnode->left = (treenode*)malloc(sizeof(treenode));
	tnode->left->val = 4;
	tnode->left->left = tnode->left->right = NULL;

	tnode->right = (treenode*)malloc(sizeof(treenode));
	tnode->right->val = 5;
	tnode->right->left = tnode->right->right = NULL;

	//Preorder_R(treehead);
	Preorder(treehead);
}

void Preorder_R(treenode * treehead)//递归算法
{
	if(treehead != NULL) {
		printf("%d", treehead->val);
		Preorder_R(treehead-> left);
		Preorder_R(treehead->right);
  	   	} else
		return;
}

void Preorder(treenode * treehead)// 一个非递归算法
{
	treenode *stack[10], *temp;
	int top = 0;
	printf("%d", treehead->val);

	if(treehead->left != NULL) {
		stack[top++] = treehead;
		treehead = treehead->left;
	} else if(treehead->right != NULL) {
		stack[top++] = treehead;
		treehead = treehead->right;
	} else {
		return;
	}

	while(top > 0) {
		if(treehead != NULL)  //遍历左子树直到叶子
			printf("%d", treehead->val);
		if(treehead->left != NULL) {
			stack[top++] = treehead;
			treehead = treehead->left;
			continue;
		}	else if(treehead->right != NULL) {
			printf("%d", treehead->val);
			stack[top++] = treehead;
			treehead = treehead->right;
			continue;
		}	
		temp = stack[--top];
		while((temp->right == treehead || temp->right == NULL)) {//判断父节点是否未遍历右子树或右子树为空
  			if((top-1) < 0)
				break;
			treehead = temp;
		    temp = stack[--top];
		}
			if(temp->right != NULL && temp->right != treehead) {
				treehead = temp->right;
				top++;
			}
	}
}

