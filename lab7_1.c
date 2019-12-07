#include <stdio.h>
#include <string.h>
typedef struct{
int size;
int f;
int r;
char arr[100][100]; 
} Q;
void push(Q *q,char *str){
if((q->r+1)%(q->size)!=(q->f)){
q->r=(q->r+1)%(q->size);
strcpy(q->arr[q->r],str);
}
else
printf("Overflow\n");
}
char* pop(Q *q){
if(q->f!=q->r)
{q->f=(q->f+1)%(q->size);
return q->arr[q->f];
}
else
printf("Underflow\n");
return '\0';
}
void disp(Q *q){
int n=(q->f+1)%(q->size);
int e=(q->r+1)%(q->size);
while(n!=e){
printf("%s\n",q->arr[n]);
n=(n+1)%(q->size);
}
}

int main(){
Q q;
q.size=100;
q.f=q.r=0;
printf("1.Push  2.Pop  3.Display   4.Exit:\n");
int n=0;
char x[100]; char buf[10];
while(n!=4)
{
scanf("%d",&n);
switch(n)
{
case 1: 
gets(buf);
printf("Enter string:");
gets(x);
push(&q,x);
break;
case 2:
printf("%s",pop(&q));
break;
case 3:
disp(&q);

break;
default:
printf("Exitng...");
}

}
}