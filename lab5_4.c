#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
 int *data;
 int top;
}stack;

int empty(stack *s)
{
 if(s->top==-1)
      return(1);
 return(0);
}

int full(stack *s, int n)
{
 if(s->top==n)
     return(1);
 return(0);
}

void push(stack *s, int n, int x)
{
 (s->top)++;
*((*s).data+(s->top))=x;
}

void pop(stack *s)
{
 s->top=s->top-1;
}

void main()
{
int n; int k; int count=0; int c;
printf("Enter length of stack : ");
scanf("%d",&n);
stack *s;
(*s).data = (int*)calloc(n,sizeof(int));
(*s).top=-1;

printf("Enter value of k:\n");
scanf("%d",&k);

printf("Enter elements:\n");
scanf("%d",&(*s).data[0]);
(*s).top++;

for(int i=1;i<n;i++)
{
  scanf("%d",&c);
  while ((*((*s).data+((*s).top-1)) < c) && (count < k))
  { 
    pop(s); 
    count++; 
    printf("COUNTER %d\n",count);
    printf("TOP %d",(*s).top);
  } 
  
  push(s,n-1,c); 
  printf("TOP %d",(*s).top);
} 

for(int i=0;i<n-count;i++)
	printf("%d  ",*((s->data)+i));

}