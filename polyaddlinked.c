#include<stdio.h>
#include <stdlib.h>
struct node
{
	int coef;
	int expo;
	struct node *link;
};
struct node *phead = NULL,*qhead=NULL,*rhead=NULL;
struct node* readpoly(struct node *head)
{
	int t,i;
	struct node *p;
	p=head;

	printf("\nEnter the number of terms  :: ");
	scanf("%d",&t);
	printf("\n");
	for(i=0;i<t;i++)
	{
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node*)); 
	 	printf("Coefficient of term %d : ",1+i);
		scanf("%d",&new->coef);
		printf("Exponent of term %d : ",i+1);
		scanf("%d",&new->expo);
		new->link=NULL;
		if(head==NULL)
		{
			head = new;
		}
		else
		{
			p=head;
			while(p->link!=NULL)
			{
				p=p->link;
			}
			p->link=new;
		
		}
	}
	return head ;
}
void display(struct node *head)
{	
	printf("\nThe  polynomial is::");
	if(head==NULL)
	{
		printf("LIST EMPTY!!!");
		
	}
	else
	{
		struct node *ptr;
		ptr=head;
		
		while(ptr->link!=NULL)
		{
			printf("%dX^%d + ",ptr->coef,ptr->expo);
			
			ptr=ptr->link;
		}
		printf("%dX^%d",ptr->coef,ptr->expo);
	}
}

void addpoly()
{
	struct node *p,*q,*r;
	p=phead;
	q=qhead;
	while(p!=NULL && q!=NULL)
	{
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node*)); 
		if(p->expo==q->expo)
		{
			new->coef=(p->coef+q->coef);
			new->expo=p->expo;
			new->link=NULL;
			p=p->link;
			q=q->link;
		}
		else if(p->expo > q->expo)
		{
			new->coef=p->coef;
			new->expo=p->expo;
			new->link=NULL;
			p=p->link;
		}
		else
		{
			new->coef=q->coef;
			new->expo=q->expo;
			new->link=NULL;
			q=q->link;
		}
		if(rhead==NULL)
		{
			rhead=new;
			r=new;
		}
		else
		{
			r->link=new;
			r=new;
		}
	}
	while(p!=NULL)
	{
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node*)); 
		new->coef=p->coef;
		new->expo=p->expo;
		new->link=NULL;
		p=p->link;
		
		if(rhead==NULL)
		{
			rhead=new;
			r=new;
		}
		else
		{
			r->link=new;
			r=new;
		}
	}
	
	while(q!=NULL)
	{
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node*)); 
		new->coef=q->coef;
		new->expo=q->expo;
		new->link=NULL;
		q=q->link;
		
		if(rhead==NULL)
		{
			rhead=new;
			r=new;
		}
		else
		{
			r->link=new;
			r=new;
		}
	}
	
	
}


int main()
{
	printf("<<<<< Polynomial addition using linked list >>>>>")
	printf("\n1st expression :: ");
	phead=readpoly(phead);
	
	printf("\nThe 1st POLYNOMIAL :: ");
	display(phead);
	
	printf("\n2nd expression :: ");
	qhead=readpoly(qhead);
	
	printf("\nThe 2nd POLYNOMIAL:: ");
	display(qhead);
	addpoly();
	printf("\n\nSum of POLYNOMIALS :");
	display(rhead);

}

/**
<<<<< Polynomial addition using linked list >>>>>
1st expression :: 
Enter the number of terms  :: 2

Coefficient of term 1 : 12
Exponent of term 1 : 3
Coefficient of term 2 : 1
Exponent of term 2 : 0

The 1st POLYNOMIAL :: 
The  polynomial is::12X^3 + 1X^0
2nd expression :: 
Enter the number of terms  :: 3

Coefficient of term 1 : 12
Exponent of term 1 : 3
Coefficient of term 2 : 2
Exponent of term 2 : 2
Coefficient of term 3 : 2
Exponent of term 3 : 0

The 2nd POLYNOMIAL:: 
The  polynomial is::12X^3 + 2X^2 + 2X^0

Sum of POLYNOMIALS :
The  polynomial is::24X^3 + 2X^2 + 3X^0

/
