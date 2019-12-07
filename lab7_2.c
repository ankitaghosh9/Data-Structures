#include <stdio.h>
#include <string.h>
typedef struct{
int size1;
int f1;
int r1;
int f2;
int r2;
int size2;
int arr[100]; 
} Q;
void push1(Q *q,int str){
if((q->r1+1)%(q->size1)!=(q->f1)){
q->r1=(q->r1+1)%(q->size1);
q->arr[q->r1]=str;
}
else
printf("Overflow..\n");
}
int pop1(Q *q){
if(q->f1!=q->r1)
{q->f1=(q->f1+1)%(q->size1);
return q->arr[q->f1];
}
else
printf("Underflow..\n");
return '\0';
}
void disp1(Q *q){
int n=(q->f1+1)%(q->size1);
int e=(q->r1+1)%(q->size1);
while(n!=e){
printf("%d\n",q->arr[n]);
n=(n+1)%(q->size1);
}
}
void push2(Q *q,int str){
if(((q->r2+1)%(q->size2)+50)!=(q->f2)){
q->r2=(q->r2+1)%(q->size2)+50;
q->arr[q->r2]=str;
}
else
printf("Overflow..\n");
}
int pop2(Q *q){
if(q->f2!=q->r2)
{q->f2=(q->f2+1)%(q->size2)+50;
return q->arr[q->f2];
}
else
printf("Underflow..\n");
return '\0';
}
void disp2(Q *q){
int n=(q->f2+1)%(q->size2)+50;
int e=(q->r2+1)%(q->size2)+50;
while(n!=e){
printf("%d\n",q->arr[n]);
n=(n+1)%(q->size2)+50;
}
}
int main(){
Q q;
q.size1=q.size2=50;
q.f1=q.r1=0;
q.f2=q.r2=50;
printf("1.Push for queue1  2.Pop for queue1 3.Display for queue1 \n4.Push for queue2 5.Pop for queue2 6.Display for queue2\n 7.exit\n");
int n=0;
int x;
while(n!=7){
scanf("%d",&n);
switch(n){
case 1: 
printf("Enter x:");
scanf("%d",&x);
push1(&q,x);
break;
case 2:
printf("%d\n",pop1(&q));
break;
case 3:
disp1(&q);
break;
case 4: 
printf("Enter x:");
scanf("%d",&x);
push2(&q,x);
break;
case 5:
printf("%d\n",pop2(&q));
break;
case 6:
disp2(&q);
break;
default:
printf("Exitng..");
}

}
}
