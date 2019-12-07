#include <stdio.h>
#include <string.h>
typedef struct{
int size1;
int f1;
int r1;
int arr[100]; 
} Q;
void push(Q *q,int str){
if((q->r1+1)%(q->size1)!=(q->f1)){
q->r1=(q->r1+1)%(q->size1);
q->arr[q->r1]=str;
}
else
printf("Overflow..\n");
}
int pop(Q *q){
if(q->f1!=q->r1)
{q->f1=(q->f1+1)%(q->size1);
return q->arr[q->f1];
}
else
printf("Underflow..\n");
return '\0';
}
void disp(Q *q){
int n=(q->f1+1)%(q->size1);
int e=(q->r1+1)%(q->size1);
while(n!=e){
printf("%d\n",q->arr[n]);
n=(n+1)%(q->size1);
}
}
int find(Q *q,int x){
int n=(q->f1+1)%(q->size1);
int e=(q->r1+1)%(q->size1);
int found=0;
int temp;
while(n!=e){
n=(n+1)%(q->size1);
temp=pop(q);
if(temp==x)
found=1;
push(q,temp);
}
return found;
}
int main(){
Q q;
q.size1=100;
q.f1=q.r1=0;

printf("1.Push 2.Pop 3.Display 4.Find 5.Exit:\n");
int n=0;
int x;
while(n!=5){
scanf("%d",&n);
switch(n){
case 1: 
printf("Enter x:");
scanf("%d",&x);
push(&q,x);
break;
case 2:
printf("%d\n",pop(&q));
break;
case 3:
disp(&q);
break;
case 4: 
printf("Enter x to be searched:");
scanf("%d",&x);
if(find(&q,x))
printf("Element exists\n");
else
printf("Element doesn't exists\n");
break;
default:
printf("Exiting...\n");
}
}
}