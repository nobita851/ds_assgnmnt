#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head;
int print()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int create()
{
    int n;
    struct node *temp,*a;
    printf("enter the no of node to be created=");
    scanf("%d",&n);
    temp=head;
    for(int i=1;i<=n;i++)
    {
        temp->next=(struct node*)malloc(sizeof(struct node));
        a=temp;
        temp=temp->next;
        printf("enter the value of node=");
        scanf("%d",&temp->data);
        temp->prev=a;
        temp->next=NULL;
    }
}
int pop()
{
    struct node *temp;
    temp=head;    
}
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the value of data=");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;
    create();
    print();
    pop();
    print;
}