#include <stdio.h>
#include <string.h>
#include<limits.h>
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
{
int min=INT_MAX;
int e;
int n;
if(q->f1<q->r1){
 n=q->f1;
e=q->r1+1;}
else{
n=q->r1;
e=q->f1+1;
}

int i;
while(n!=e){

if(q->arr[n]<min && q->arr[n]!=INT_MIN){
min=q->arr[n];
i=n;
}
n++;
}
q->arr[i]=INT_MIN;
if(min!=INT_MIN)
return min;
else
printf("Underflow..\n");
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

int main(){
Q q;
q.size1=100;
q.f1=q.r1=0;

printf("1.push1,2.pop1,3.disp1,-1.exit:");
int n=0;
int x;
while(n!=-1){
scanf("%d",&n);
switch(n){
case 1: 
printf("ENter x:");
scanf("%d",&x);
push(&q,x);
break;
case 2:
printf("%d",pop(&q));
break;
case 3:
disp(&q);
break;

default:
printf("exiting..");
}
}
}
