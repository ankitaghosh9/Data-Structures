#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10

typedef struct node *Nodeptr;
typedef struct node 
{ 
	int data; 
	Nodeptr lchild;
	Nodeptr rchild; 
}Node; 

typedef struct stack 
{ 
	int top; 
	Nodeptr *array; 
}Stack; 

Nodeptr newNode() 
{ 
	Nodeptr temp= (Nodeptr)malloc(sizeof(Node)); 
	temp->lchild = temp->rchild = NULL; 
	return temp; 
} 

// A utility function to create a stack of given size 
Stack* createStack(int size) 
{ 
	Stack *s = (Stack*) malloc(sizeof(Stack)); 
	s->top = -1; 
	s->array = (Nodeptr*) malloc(MAX * sizeof(Nodeptr)); 
	return s; 
} 

Nodeptr createBT(int item)
{
	int x;
	if(item!=-1)
	{
		Nodeptr temp=newNode();
		temp->data=item;

		printf("Enter left child of %d:", item);
		scanf("%d",&x);
		temp->lchild = createBT(x);

        printf("Enter right child of %d:", item);
		scanf("%d",&x);
		temp->rchild = createBT(x);

		return temp;
	}
	return NULL;
}


// BASIC OPERATIONS OF STACK 
int isFull(Stack *s) 
{ 
	if(s->top - 1 == MAX)
		return 1;
	return 0;
 } 

int isEmpty(Stack *s) 
{
	if(s->top == -1)
		return 1;
	return 0;
 } 

void push(Stack *s, Nodeptr node) 
{ 
	if (isFull(s)==1) 
		return; 
	s->array[++s->top] = node; 
} 

Nodeptr pop(Stack *s) 
{ 
	if (isEmpty(s)==1) 
		return NULL; 
	return s->array[s->top--]; 
} 

Nodeptr peek(Stack *s) 
{ 
	if (isEmpty(s)==1) 
		return NULL; 
	return s->array[s->top]; 
} 

void postOrderIterative(Nodeptr root) 
{ 
	if (root == NULL) 
		return; 
	
	Stack *s= createStack(MAX); 
	do
	{ 
		while (root) 
		{  
			if (root->rchild) 
				push(s, root->rchild); 
			push(s, root); 
			root = root->lchild; 
		}  
		root = pop(s); 
		if (root->rchild && peek(s) == root->rchild) 
		{ 
			pop(s); 
			push(s, root); 
			root = root->rchild; 
		} 
		else  
		{ 
			printf("%d ", root->data); 
			root = NULL; 
		} 
	} while (!isEmpty(s)); 
} 

void inOrderIterative(Nodeptr root)
{
	Stack *s= createStack(MAX);
	Nodeptr current;
	int flag=0;

    if(root==NULL)
    {
    	printf("Empty tree");
    	return;
    }
    current=root;
	while(!flag)
	{
		while(current)
		{
			push(s,current);
			current=current->lchild;
		}
		if(isEmpty(s)==0)
		{
			current=pop(s);
			printf("%d ",current->data);
			current=current->rchild;
		}
		else
			flag=1;
	}
}

int main()
{
	Nodeptr root;
	root=NULL;
	printf("1.Insert  2.Inorder  3.Postorder  4.Preorder  5.Levelorder  6.Exit\n");
	int n=0;
	int x;
	while(n!=6)
	{
	scanf("%d",&n);
	switch(n)
	{
	case 1: 
	printf("Enter node:");
	scanf("%d", &x);
	root=createBT(x);
	break;
	case 2:
	inOrderIterative(root);
	printf("\n");
	break;
	case 3:
	postOrderIterative(root);
	printf("\n");
	break;
	/*
	case 4:
	preorder(root);
	printf("\n");
	break;
	case 5:
	levelOrderIterative(root);
	printf("\n");
	break;
	*/
	default:
	printf("Exitng...");
	}

   }
}


