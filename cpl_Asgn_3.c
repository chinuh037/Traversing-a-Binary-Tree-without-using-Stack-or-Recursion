#include<stdio.h>
#include<stdlib.h>



typedef struct tNode
{
	int status;				//"0" for unmarked , "1" for marked
	struct tNode * left;
	struct tNode * right;
}tNode;


		
tNode * new_node(int data) 
{
    tNode * ret_node = (tNode *)malloc(sizeof(tNode));

    // Setting up data values
   
    ret_node->status = 0;
    ret_node->left = NULL;
    ret_node->right = NULL;

    return ret_node;
}
		
tNode * Make_tree(int lo,int hi)				// Recursive FUnction to just Make a Binary tree
{
	int mid = (lo + hi)/2;
	
	if(mid == lo || mid == hi)
	{
		return NULL;
	}
	else
	{
		tNode * ret_node = new_node(mid);
		ret_node->left = Make_tree(lo,mid);
		ret_node->right = Make_tree(mid,hi);
		
		return ret_node;
	}
}	
	

void Traversal(struct tNode * root)
{
  struct tNode * current; 
  struct tNode * pre;

  if(root == NULL)
     return; 

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      current->status=1;
      current = current->right;
    }
    else
    {
      
	    pre = current->left;
	    while(pre->right != NULL && pre->right != current)
        pre = pre->right;
	
	      
	    if(pre->right == NULL)
	    {
	    	pre->right = current;
	        current = current->left;
	    }
		else
	    {
	  		pre->right = NULL;
	    	current->status=1;
	        current = current->right;
	    } 
    } 
  } 
}

void print_Inorder(tNode * root)
{
	if ( root == NULL)
	{
		return;
	}
	
	print_Inorder( root->left );
	
	printf("%d\n",root->status);
	
	print_Inorder( root->right );
	
	
}

int main()
{
	tNode * root;
	root = Make_tree(0,15);				//height upto 4 levels
	
	Traversal(root);				//traversal without using stack or recursion
	
	print_Inorder(root);			//This recursive function is just to print the status(0 = unvisited , 1 = Visited )
	
	return 0;
}
