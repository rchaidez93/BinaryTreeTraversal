#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#define MARKER -1

void PrintInorder(treeNode *node, FILE *fp, int h)
{
		
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left,fp,h+1);
		for(int i = 0; i < h; i++)
		{
			fprintf(fp, " ");
		}
		fprintf(fp,"%d:%d\n",node->data, node->count);
        PrintInorder(node->right,fp,h+1);
		
		
}

void PrintPreorder(treeNode *node, FILE *fp, int h)
{
        if(node==NULL)
        {
                return;
        }
		for(int i = 0; i < h; i++)
		{
			fprintf(fp, " ");
		}
        fprintf(fp,"%d:%d\n",node->data, node->count);
        PrintPreorder(node->left, fp,h+1);
        PrintPreorder(node->right, fp, h+1);
}

void PrintPostorder(treeNode *node, FILE *fp, int h)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left, fp, h+1);
        PrintPostorder(node->right, fp, h+1);
		for(int i = 0; i < h; i++)
		{
			fprintf(fp, " ");
		}
        fprintf(fp,"%d:%d\n",node->data, node->count);
}
