#include <stdio.h>
#include <stdlib.h>
typedef struct node *Nodeptr;

typedef struct node
{
	int data;
	Nodeptr rchild;
	Nodeptr lchild;	
}Node;

Nodeptr getNode()
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
	temp->rchild=NULL;
	temp->lchild=NULL;
	return temp;
}

Nodeptr createBT(int item)
{
	int x;
	if(item!=-1)
	{
		Nodeptr temp=getNode();
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

void inorder(Nodeptr p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		printf("%d", p->data);
		inorder(p->rchild);
	}
}

void postorder(Nodeptr p)
{
	if(p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d", p->data);
	}
}

void preorder(Nodeptr p)
{
	if(p!=NULL)
	{
		printf("%d", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

int main()
{
	Nodeptr root;
	root=NULL;
	printf("1.Insert  2.Inorder  3.Postorder  4.Preorder  5.Exit\n");
	int n=0;
	int x;
	while(n!=5)
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
	inorder(root);
	printf("\n");
	break;
	case 3:
	postorder(root);
	printf("\n");
	break;
	case 4:
	preorder(root);
	printf("\n");
	break;
	default:
	printf("Exitng...");
	}

   }
}

