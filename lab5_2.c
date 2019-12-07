#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct
{
 int data[MAX];
 int top;
}stack;

int empty(stack *s)
{
 if(s->top==-1)
      return(1);
 return(0);
}

int full(stack *s)
{
 if(s->top==MAX-1)
     return(1);
 return(0);
}

void push(stack *s,int x)
{
 s->top=s->top+1;
 s->data[s->top]=x;
}

int pop(stack *s)
{
 int x;
 x=s->data[s->top];
 s->top=s->top-1;
 return(x);
}

void main()
{
 stack *s;
 int num;

 (*s).top=-1;
     printf("Enter decimal number:\n");
     scanf("%d",&num);

     while((num!=0))
     {
       if(!full(s))
          {
          push(s,num%2);
          num=num/2;
          }
       else
          {
          printf("Stack overflow");
          exit(0);
          }
     }

    while(!empty(s))
       {
       num=pop(s);
       printf("%d",num);
       }
    printf("\n");
}