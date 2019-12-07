#include <stdio.h>
#include <string.h>
typedef struct {
char arr[100];
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
int isFull(Q *q){#include <stdio.h>
#include <string.h>
typedef struct {
char arr[100];
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
char dequeR(Q *q){
if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char p;
p=q->arr[q->f];
init(q);
return p;
}
else{
char p;
p=q->arr[q->r];
q->r=(q->r+q->size-1)%(q->size);
return p;
}
}
}

char dequeL(Q *q){

if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char p;
p=q->arr[q->f];
init(q);
return p;
}
else{
char p;
p=q->arr[q->f];
q->f=(q->f+1)%(q->size);
return p;
}
}
}
void enqueR(Q *q,char str){

if(isEmpty(q)){
q->r=0;
q->f=0;
q->arr[q->r]=str;
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->r=(q->r+1)%(q->size);
q->arr[q->r]=str;
}
}

void enqueL(Q *q,char str){

if(isEmpty(q)){
q->r=0;
q->f=0;
q->arr[q->r]=str;
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->f=(q->f+q->size-1)%(q->size);
q->arr[q->f]=str;
}
}
int isPalin(Q *q,char *str){
for(int i=0;i<strlen(str);i++){
enqueR(q,str[i]);
}
for(int i=0;i<strlen(str)/2;i++){
if(dequeL(q)!=dequeR(q))
return 0;
}
return 1;
}
int main(){
Q q;
init(&q);
char str[100];
printf("ENTER STRING");
scanf("%s",str);


if(isPalin(&q,str)){
printf("Palindrome");
}
else
printf("Not Palindrome");
}
if((q->r+1)%(q->size)==(q->f))
return 1;
return 0;
}
char dequeR(Q *q){
if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char p;
strcpy(&p,&(q->arr[q->f]));
init(q);
return p;
}
else{
char p;
strcpy(&p,&(q->arr[q->r]));
q->r=(q->r+q->size-1)%(q->size);
return p;
}
}
}

char dequeL(Q *q){

if(isEmpty(q)){
printf("Underflow\n");
return '\0';
}
else{
if(q->r==q->f)
{char p;
strcpy(&p,&(q->arr[q->f]));
init(q);
return p;
}
else{
char p;
strcpy(&p,&(q->arr[q->f]));
q->f=(q->f+1)%(q->size);
return p;
}
}
}
void enqueR(Q *q,char *str){

if(isEmpty(q)){
q->r=0;
q->f=0;
strcpy(&(q->arr[q->r]),str);
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->r=(q->r+1)%(q->size);
strcpy(&(q->arr[q->r]),str);
}
}

void enqueL(Q *q,char *str){

if(isEmpty(q)){
q->r=0;
q->f=0;
strcpy(&(q->arr[q->r]),str);
}
else if(isFull(q)){


printf("Overflow\n");

}
else{
q->f=(q->f+q->size-1)%(q->size);
strcpy(&(q->arr[q->f]),str);
}
}
int isPalin(Q *q,char *str){
for(int i=0;i<strlen(str);i++){
enqueR(q,&str[i]);
}
while(!isEmpty(q)){
if(dequeL(q)!=dequeR(q))
return 0;
}
return 1;
}
int main(){
Q q;
init(&q);
char str[100];
printf("ENTER STRING");
scanf("%s",str);
if(isPalin){
printf("Palindrome");
}
else
printf("Not Palindrome");
}
