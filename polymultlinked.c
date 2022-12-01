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

void multpoly()
{
	struct node *p,*q,*r,*prev,*new;
	p=phead;
	q=qhead;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			new=(struct node*)malloc(sizeof(struct node*));
			new->coef=(p->coef*q->coef);
			new->expo=p->expo+q->expo;
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
		p=p->link;
		q=qhead;
	}
	
	p=rhead;
	while(p!=NULL)
	{
		prev=p;
		q=p->link;
		while(q!=NULL)
		{
			if(p->expo==q->expo)
			{
				p->coef=(p->coef+q->coef);
				prev->link=q->link;
				free(q);
				q=prev->link;
			}
			else
			{
				prev=q;
				q=q->link;
			}
			
		}
		p=p->link;
	}
	
}

int main()
{
	printf("<<<<< Polynomial Multiplication using linked list >>>>>");
	printf("\n1st expression :: ");
	phead=readpoly(phead);
	
	printf("\nThe 1st POLYNOMIAL :: ");
	display(phead);
	
	printf("\n2nd expression :: ");
	qhead=readpoly(qhead);
	
	printf("\nThe 2nd POLYNOMIAL:: ");
	display(qhead);
	multpoly();
	printf("\n\nProduct of POLYNOMIALS :");
	display(rhead);	
}

/*
<<<<< Polynomial Multiplication using linked list >>>>>
1st expression :: 
Enter the number of terms  :: 3

Coefficient of term 1 : 6
Exponent of term 1 : 3
Coefficient of term 2 : 2
Exponent of term 2 : 2
Coefficient of term 3 : 7
Exponent of term 3 : 0

The 1st POLYNOMIAL :: 
The  polynomial is::6X^3 + 2X^2 + 7X^0
2nd expression :: 
Enter the number of terms  :: 2

Coefficient of term 1 : 6
Exponent of term 1 : 3
Coefficient of term 2 : 8
Exponent of term 2 : 1

The 2nd POLYNOMIAL:: 
The  polynomial is::6X^3 + 8X^1

Product of POLYNOMIALS :
The  polynomial is::36X^6 + 48X^4 + 12X^5 + 58X^3 + 56X^1
*/
