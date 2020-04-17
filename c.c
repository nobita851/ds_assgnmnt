#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stackarr[50];int top=-1;

void main()
{ char c;
    char infix[50];
     printf("enter the infix expression\n");
    scanf("%s",&infix);
   printf("the postfix expression is :");
    int m=0, n=strlen(infix);

    while(n)
    {
        if(infix[m]==('^')||infix[m]==('*')||infix[m]==('/')||infix[m]==('+')||infix[m]==('-')||infix[m]==('(')||infix[m]==(')'))
        {
          c=infix[m];
         stack(c);
        }
        else
        {
            printf("%c",infix[m]);
        }
        n--;
        m++;
    }
    while(top+1)
    {
        pop();
    }
}
void stack (char c)
{
if(top==-1||c=='(')
    push(c);
else
compare(c);
}

void push( char z)
{   top++;
    stackarr[top]=z;
}
void pop()
{

    if(top==-1)
    {
        printf("there is no data to delete ");
    }
    else
    {
        printf("%c",stackarr[top]);
        top--;

    }
}
void compare(char y)
{
    if(y==stackarr[top]||(y=='+'&&stackarr[top]=='-')||(y=='-'&&stackarr[top]=='+')||(y=='*'&&stackarr[top]=='/')||(y=='/'&&stackarr[top]=='*'))
    {
        if(y=='^')
        push(y);
        else
        {
          pop();
          stack(y) ;
        }
    }
    else
    {
        if(stackarr[top]=='+'||stackarr[top]=='-'||stackarr[top]=='(')
            push(y);
        else
        {
            if(stackarr[top]=='*'&&y=='^')
                push(y);
                else
                {
                    if((y=='+'||y=='-')&&(stackarr[top]=='^'||stackarr[top]=='*'||stackarr[top]=='/'))
                    {
                        pop();
                        stack(y);
                    }
                    else
                    {
                        if((y=='*'||y=='/')&&(stackarr[top]=='^'))
                        {
                                pop();
                        stack(y);
                    }
                    else
                    {
                        while(stackarr[top]!='(')
                        {
                            pop();
                        }
                        top--;
                    }
                        }
                }

        }
    }
}