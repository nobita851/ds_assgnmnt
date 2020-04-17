#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
void store(struct node* temp,int arr[],int *ind) 
{ 
    if (temp==NULL) 
        return; 
    store(temp->left,arr,ind); 
    arr[*ind]=temp->data; 
    (*ind)++;
    store(temp->right,arr,ind); 
}
void Sort(int arr[],int n)  
{  
    int i, key, j;  
    for (i=1;i<n;i++) 
    {  
        key=arr[i];  
        j=i-1;  
        while(j>=0&&arr[j]>key) 
        {  
            arr[j+1]=arr[j];  
            j=j-1;  
        }  
        arr[j+1]=key;  
    }  
}
void BST(int *arr,struct node* temp,int *ind) 
{  
    if (temp==NULL) 
      return;
    BST(arr,temp->left,ind);
    temp->data=arr[*ind]; 
    (*ind)++;
    BST(arr,temp->right,ind); 
}  
int create(struct node *temp)
{
    int n=0;
    if(temp)
    {
        temp->left=(struct node *)malloc(sizeof(struct node));
		if (temp->left)
		{
            printf("Enter data to  left of \"%d\" :",temp->data);
            scanf("%d",&temp->left->data);
            if(temp->left->data==-1)
            {
                temp->left=NULL;
            }
            else
                n=n+1+create(temp->left);
        }
        else
        {
            printf("Something went wrong while creating left node");
            return 0;
        }

        temp->right=(struct node *)malloc(sizeof(struct node));
		if (temp->right)
		{
            printf("Enter data to right of \"%d\" :",temp->data);
            scanf("%d",&temp->right->data);
            if(temp->right->data==-1)
            {
                temp->right=NULL;
            }
            else
            n=n+1+create(temp->right);
        }
        else
        {
            printf("Something went wrong while creating right node");
            return 0;
        }
    }
    return n;
}
int he(struct node *temp)
{
    int lt=1,rt=1;
    if(!temp->left)
        lt=1;
    else
        lt=1+he(temp->left);    
    if(!temp->right)
        rt=1;
    else
        rt=1+he(temp->right);
    if(lt>rt)
        return lt;
    else 
        return rt;    
}
int leaf(struct node *temp)
{
    if(temp->left==NULL&&temp->right==NULL)
        return 1;
    else if(temp)
        return NULL;
    else
        return(leaf(temp->left)+leaf(temp->right));
}
void createBST() 
{
    root=(struct node *)malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("Memory not allocated");
	}
	else
	{
        printf("\n-1 equals null");
        printf("\nEnter rooot data:");
        scanf("%d",&root->data);
    }
    int n=create(root)+1;
    int n1=leaf(root);
    printf("BT Converted To BST with same structure.\nNumber of Nodes=%d\nNumber of leaf Nodes=%d\nNumber of non-leaf Nodes=%d",n,n1,n-n1);
    printf("\nThe height of tree is:  %d",he(root));
    int *arr=(int *)calloc(n,sizeof(int)); 
    int i=0;
    store(root,arr,&i); 
    Sort(arr,n); 
    i=0; 
    BST(arr,root,&i);
    free(arr); 
} 
void main()
{
    createBST(); 
}