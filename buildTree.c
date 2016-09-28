#include <stdlib.h>
#include "node.h"


treeNode * newNode(int data)
{
	 
        treeNode *temp;
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
		temp ->count = 1;
        return temp;
       
}

treeNode * Create(treeNode *node,int data)
{
       //if tree is empty return new node
		if(node == NULL)
			return newNode(data);
		
		//if data already exists in the tree, count will be incremented
		if(data == node->data)
		{
			(node->count)++;
			return node;
		}

        if(data >(node->data))
        {
                node->right = Create(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Create(node->left,data);
        }
        return node;

}