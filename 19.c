
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
    struct node* rchild;
};
struct node *root=NULL;
struct node *par,*loc;
void find(int);
void del(int);
void case1();
void case2();
void case3();
void insert(int);
void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);
void quit();
int main()
{
int item;
char c;
while(1)
{
printf("\n_________________________________\n");
printf("\t\tMENU:");
printf("\nPress a,INSERT");
printf("\nPress f,FIND ELEMENT");
printf("\nPress d,DELETE ANY DATA");
printf("\nPress o,DISPLAY ELEMENT IN PREORDER");
printf("\nPress n,DISPLAY ELEMENT IN POSTORDER");
printf("\nPress m,DISPLAY ELEMENT IN INORDER");
printf("\nPress q,QUIT\n");
printf("\nInput:");
fflush(stdin);
scanf("%c",&c);
switch(c)
{case 'a':
case 'A':
printf("Enter element to add:");
scanf("%d",&item);
insert(item);
break;
case 'f':
case 'F':
printf("Enter element to find:");
scanf("%d",&item);
find(item);
if (loc!=NULL)
printf("\n\t\tFOUND\n");
else
printf("\n\t\tNOT FOUND\n");
break;
case 'd':
case 'D':
printf("Enter element to delete:");
scanf("%d",&item);
del(item);
break;
case 'O':
case 'o':
printf("OUTPUT=\n\t");
preorder(root);
break;
case 'm':
case 'M':
printf("OUTPUT=\n\t");
inorder(root);
break;
case 'N':
case 'n':
printf("OUTPUT=\n\t");
postorder(root);
break;
case 'q':
case 'Q':quit();
default:printf("Invalid input!!!");
}
}
return 0;
}
void find(int item)
{
struct node *ptrloc,*ptrpar;
if (root==NULL)
{
par=NULL;
loc=NULL;
return;
}
if (item==root->data)
{
par=NULL;
loc=root;
return;
}
if (item>root->data)
{
ptrpar=root;
ptrloc=root->rchild;
}
else if(item<root->data)
{
ptrpar=root;
ptrloc=root->lchild;
}
while(ptrloc!=NULL)
{
if (item==ptrloc->data)
{
par=ptrpar;
loc=ptrloc;
return;
}
if (item>ptrloc->data)
{
ptrpar=ptrloc;
ptrloc=ptrloc->rchild;
}
else if(item<ptrloc->data)
{
ptrpar=ptrloc;
ptrloc=ptrloc->lchild;
}
}
par=ptrpar;
loc=NULL;
}
void insert(int item)
{
struct node* temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=item;
temp->lchild=NULL;
temp->rchild=NULL;
if (root==NULL)
{
root=temp;
return;
}
find(item);
if (loc!=NULL)
{
printf("ELEMENT ALREADY EXIST");
free(temp);
return;
}
if(par->data>item)
{par->lchild=temp;
 }
 else if(par->data<item)
{par->rchild=temp;
}
}
void inorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	inorder(ptr->lchild);
	printf("%d\t",ptr->data);
	inorder(ptr->rchild);
	}
}
void postorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d\t",ptr->data);
	}
}
void preorder(struct node *ptr)
{
	if (ptr!=NULL)
	{
	printf("%d\t",ptr->data);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
	}
}
void quit()
{char d;
printf("\nYou really want to exit[y]:");
fflush(stdin);
scanf("%c",&d);
if(d=='y')
exit(0);
}
void del(int item)
{
	if(root==NULL)
	{
	printf("tree is empty");
	return;
	}
	find(item);
		if(loc==NULL)
		{
			printf("element not found");
			return;
		}
		if(loc->lchild==NULL&&loc->rchild==NULL)
		{
			case1();
		}
		if(loc->lchild!=NULL&&loc->rchild==NULL)
		{	
		case2();
	    }
		if(loc->lchild==NULL&&loc->rchild!=NULL)
		{	
		case2();
	    }
		if(loc->lchild!=NULL&&loc->rchild!=NULL)
		{	
		case3();
	    }
	    free(loc);
}
void case1()
{
	if(par==NULL)
	{
		root=NULL;
		return;
	}
	if( par->lchild==loc)
	{
		par->lchild=NULL;
	}
	if(par->rchild==loc)
	{
		par->rchild=NULL;
	}
}
void case2()
{
	struct node*child;
		if(par==NULL)
	    {
		if(loc->lchild!=NULL)
		{
			root=loc->lchild;
		}
		else if(loc->rchild!=NULL)
		{
			root=loc->rchild;
		}
      	}
    if(loc->lchild!=NULL)
	{
		child=loc->lchild;
	}
	if(loc->rchild!=NULL)
	{
		child=loc->rchild;
	}
	if(par->lchild==loc)
	{
		par->lchild=child;
	}
	if(par->rchild==loc)
	{
		par->rchild=child;
	}
	}
	
	void case3()
	{   
	struct node *parsucc,*succ;
		succ=loc->rchild;
		parsucc=loc;
	while(succ->lchild!=NULL)
	{
		parsucc=succ;
		succ=succ->lchild;
	}
	if(succ->rchild==NULL)
	{   loc=succ;
	    par=parsucc;
		case1();
	}
	else if(succ->rchild!=NULL)
	{   loc=succ;
	    par=parsucc;
		case2();
	}
	if(par->rchild==loc)
	{
		par->rchild=succ;
	}
	else if(par->lchild==loc)
	{
	par->lchild=succ;
    }
succ->lchild=loc->lchild;
succ->rchild=loc->rchild;	
}


