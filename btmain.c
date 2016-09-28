#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "buildTree.h"
#include "traversals.h"

/*
	Creator: Richard Chaidez
	Date: 9/28/16
	Project: Binary Tree Traversal with count and indentation
	About:	Program take an optional arguments which is a file to be read from that contains the elements to insert to the tree.
			If there is no argument, then the user will be asked how many elements they would like to insert and insert them. 
			The program then creates the tree with the elements and prints them in inorder,preorder, and postorder. If a node 
			inserts a node that already exist the program will increment that node count instead of inserting it. Depending on
			what level that node is on it will be indented accordingly. 

*/




//get height of tree and indent the tree according to height
int height(treeNode* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       // compute the depth of each subtree 
       int lheight = height(node->left);
       int rheight = height(node->right);
 
       // use the larger one 
       if (lheight > rheight) 
           return(lheight+1);
       else return(rheight+1);
   }
}
//			***MAIN***
int main(int argc, char *argv[])
{
	//no argument on command line
	if(!argv[1]){
		//input the elements to tree
		int n,i;
		printf("Enter number of elements: ");
		scanf("%d",&n);
		int integers[n];
		printf("Enter the %d elements\n", n);
		//get elements
		for(int c = 0; c < n; c++)
			scanf("%d", &integers[c]);
		//create the tree
		treeNode *root = NULL;
		for(i=0; i < n; i++)
		{
			root = Create(root, integers[i]);
		}
		int h = height(root);
		printf("\n");
		
		//send inorder tree traversal to out.inorder file
		FILE *infp = fopen("out.inorder", "w");
		 if (infp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintInorder(root,infp, h);
		fclose(infp);
		printf("\n");
		//send preorder tree traversal to out.preorder file 
		FILE *prfp = fopen("out.preorder", "w");
		 if (prfp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintPreorder(root, prfp,h);
		fclose(prfp);
		printf("\n"); 
		//send postorder tree traversal to out. postorder file
		FILE *pofp = fopen("out.postorder", "w");
		 if (pofp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintPostorder(root, pofp,h);
		fclose(pofp);
		printf("\n");
	}
	//there is a file argument on command line to read
	else
	{
		FILE *fr; 
		fr = fopen (argv[1], "r");
		if(fr == 0)
		{
			printf("could not open file\n");
		}
		int size = 1;
		printf("\nFile opened ");
		int ch;
		do{
			ch = fgetc(fr);
			if(ch == ' ')
				++size;
		}while(ch != EOF);
		
		printf("The size of given file is : %d\n", size);
		fclose(fr);
		
		
		int array[size],i =0;
		FILE *fp; 
		fp = fopen (argv[1], "r");
		//copy elements in file to array
		while (!feof(fp)) {
			if (fscanf(fp,"%ld", &array[i]) != 1) {
				continue;
			}
			printf("%ld\n",array[i]);
			i++;
    }
			printf("\n");
			fclose(fp);
		//create tree
		treeNode *root = NULL;	
		for(i=0; i < size; i++)
		{
			root = Create(root, array[i]);
		}
		int h = height(root);
		printf("\n");
		char infile[255];
		strcpy(infile, argv[1]);
		strcat(infile, ".inorder");
		FILE *infp = fopen(infile, "w");
		if(infp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintInorder(root,infp,h);
		fclose(infp);
		printf("\n");
        
		char prefile[255];
		strcpy(prefile, argv[1]);
		strcat(prefile, ".preorder");
		FILE *prfp = fopen(prefile, "w");
		if(prfp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintPreorder(root,prfp,h);
		fclose(prfp);
		printf("\n");
		
		char postfile[255];
		strcpy(postfile, argv[1]);
		strcat(postfile, ".postorder");
		FILE *pofp = fopen(postfile, "w");
		if(pofp == NULL)
		{
			printf("Could not open file");
			return 0;
		}
		PrintPostorder(root,pofp,h);
		fclose(pofp);
		printf("\n");
	}
   return 0;
}