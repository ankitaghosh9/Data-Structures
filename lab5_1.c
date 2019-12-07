#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
char *a;
int top;
}STACK;

int isEmpty(STACK *s)
{
if(s->top == -1)
	return 1;
else
    return 0;
}

int isFull(STACK *s, int x)
{
if(s->top == x) 
	return 1;
else
    return 0;
}

void push(STACK *s, char ele, int x)
{
if(isFull(s,x))
{
printf("Stack Overflow\n");
}
else
{
(s->top)++;
*((*s).a+(s->top))=ele;
}
}

char pop(STACK *s)
{
if(isEmpty(s))
{
printf("Stack Underflow\n");
}
else
{
(*s).top--;
return *((*s).a+(s->top));
}
}

void display(STACK *s)
{
for(int i=0;i<=((*s).top);i++)
{
printf("%c ",*((*s).a+i));
}
printf("\n");
}

void main()
{
int n; int no=0;
char c;
char x;
printf("Enter length of stack : ");
scanf("%d",&n);
fflush(stdin);
STACK *s;
(*s).a = (char*)calloc(n,sizeof(char));
(*s).top=-1;

printf("Enter elements:\n");
for(int i=0;i<n;i++)
{
  scanf("%c",&x);
  scanf("%c",&c);
  push(s,c,n);
}
display(s);

printf("1.Push 2.Pop 3.Display 4.Exit: ");
while(no!=4)
{
	scanf("%d",&no);
	switch(no)
	{
		case 1:
		printf("Enter element:");
		scanf("%c",&x);
        scanf("%c",&c);
        push(s,c,n-1);
		break;
		case 2:
		pop(s);
		break;
		case 3:
		display(s);
		break;
		case 4:
		default:
		exit(0);
	}
}

}