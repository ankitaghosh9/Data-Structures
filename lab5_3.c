#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct
{
    int top;
    char stack[MAX];
    
}STACK;

 
void push(STACK *s, char a)
{
    s->top++;
    s->stack[s->top]  =  a;
}
 
void pop(STACK *s)
{
    s->top--;
}
 
void main()
{
    int i; int front=0; char str[MAX];
    STACK s; 
    s.top=-1;

            printf("Enter the String\n");
            gets(str);
            for (i = 0;str[i]!='\0'; i++)
                push(&s,str[i]);
            for (i = 0;i < (strlen(str) / 2);i++)
            {
                if (s.stack[s.top] == s.stack[front])
                {
                    pop(&s);
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", str);
                    exit(0); 
                }
            }
            if ((strlen(str) / 2)==front)
                printf("%s is palindrome\n",  str);
            
}
