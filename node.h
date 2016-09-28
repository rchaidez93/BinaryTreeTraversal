#ifndef NODE_H
#define NODE_H

typedef struct treeNode
{
        int data;
		int count;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

#endif