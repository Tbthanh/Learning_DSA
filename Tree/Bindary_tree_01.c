#include <stdio.h>
#include <stdlib.h>

//create ADT of bindary tree
typedef struct btNode
{
	int data;
	btNode *left;
	btNode *right;		
}btNode;

//Initialize the memory for tree node
btNode* creNode()
{
	btNode *btn = malloc(sizeof(btNode));
	if(!btn)
		return NULL;
	
	btn->left = btn->right = NULL;
	
	return btn;
}

//PreOrder traversal
void preOrder(btNode *root)
{
	if(root)
	{
		printf(" %d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//InOrder traversal
void inOrder(btNode *root)
{
	if(root)
	{
		inOrder(root->left);
		printf(" %d ",root->data);
		inOrder(root->right);
	}
}

//PostOrder traversal
void postOrder(btNode *root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ", root->data);
	}
}

//

int main()
{
	
	return 0;
}
