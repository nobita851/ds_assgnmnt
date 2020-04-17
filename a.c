#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head;
void initialize(struct node *temp,int n)
{
    for(int i=1;i<=n;i++)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
temp->link=newnode;
temp=temp->link;
printf("enter the data of the node=");
scanf("%d",&(temp->data));
temp->link=NULL;
}
}
void print(struct node *temp)
{
while(temp)
{
    printf("%d\n",(temp->data));
    temp=temp->link;
}
}
void insert(struct node *temp,int d)
{
    while(temp->data!=d)
    {
        temp=temp->link;
    }
    struct node *in=temp->link;
    temp->link=(struct node *)malloc(sizeof(struct node));
    temp=temp->link;
    printf("enter the value of data of new node=");
    scanf("%d",&(temp->data));
    temp->link=in;
}
void delete(struct node *temp,int del,int el)
{
    while((temp->link)->data!=el)
    {
        temp=temp->link;
    }
    free(temp->link);
    temp->link=NULL;
}
void reverse(struct node*temp)
{
    struct node *prev,*next;
    prev=NULL;
    while(temp->link!=NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    temp->link=prev;
    head=temp;
    
}
int push()
{
    struct node*temp=head;
    struct node*ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=8;
    ptr->link=temp;
    head=ptr;
}
void pop()
{
    struct node*temp=head;
    head=head->link;
    free(temp);
}
void recursive(struct node *temp)
{
    if(temp->link!=NULL)
    {
        recursive(temp->link);
        printf("%d\n",temp->data);
    }
    else
    {
        printf("%d\n",temp->data);
    }
    
}
int main()
{
    head=(struct node *)malloc(sizeof(struct node));
if(head==NULL)
{
    printf("memory not allocated");
}
printf("enter the value of data=");
scanf("%d",&(head->data));
struct node *temp;
temp=head;
temp->link=NULL;
printf("enter the no of new nodes to be created=");
int n;
scanf("%d",&n);
initialize(head,n);
print(head);
printf("Enter the data after which node is to be inserted\n");
int d;
scanf("%d",&d);
insert(head,d);
print(head);
printf("enter no of elements to be deleted=");
int del;
scanf("%d",&del);
printf("enter the data after elements are to be deleted=");
int el;
scanf("%d",&el);
delete(head,del,el);
print(head);
reverse(head);
print(head);
push();
printf("inserting a node\n");
print(head);
pop();
printf("deleting a node\n");
print(head);
printf("recursion\n");
recursive(head);
}