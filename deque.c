#include <stdio.h>
#include <string.h>
typedef struct {
char arr[100][100];
int size;
int f,r;
}Q;
void init(Q *q){
q->f=-1;
q->r=-1;
q->size=100;
}
int isEmpty(Q *q){
if(q->r==-1)
return 1;
return 0;
}
int isFull(Q *q){
if((q->r+1)%(q->size)==(q->f))
return 1;
return 0;
}
char* dequeR(Q *q){
if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char *p;
p=q->arr[q->f];
init(q);
return p;
}
else{
char *p;
p=q->arr[q->r];
q->r=(q->r+q->size-1)%(q->size);
return p;
}
}
}

char* dequeL(Q *q){

if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char *p;
p=q->arr[q->f];
init(q);
return p;
}
else{
char *p;
p=q->arr[q->f];
q->f=(q->f+1)%(q->size);
return p;
}
}
}
void enqueR(Q *q,char *str){

if(isEmpty(q)){
q->r=0;
q->f=0;
strcpy(q->arr[q->r],str);
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->r=(q->r+1)%(q->size);
strcpy(q->arr[q->r],str);
}
}

void enqueL(Q *q,char *str){

if(isEmpty(q)){
q->r=0;
q->f=0;
strcpy(q->arr[q->r],str);
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->f=(q->f+q->size-1)%(q->size);
strcpy(q->arr[q->f],str);
}
}
int main(){
Q q;
init(&q);
printf("1.INSERT L\n2.INSERT R\n3.DEL L\n-1.EXIT");
char str[100];
int n=0;
while(n!=-1){
switch(n){
case 1:
printf("ENTER STRING");
scanf("%s",str);
enqueL(&q,str);
break;
case 2:
printf("ENTER STRING");
scanf("%s",str);
enqueR(&q,str);
break;
case 3:
printf("%s",dequeL(&q));
break;
default:
printf("EXITING..");
}

scanf("%d",&n);
}
}
