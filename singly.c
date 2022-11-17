#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node *head= NULL;

void display()
{	
	if(head==NULL)
	{
		printf("LIST EMPTY!!!");
		
	}
	else
	{
		struct node *ptr;
		ptr=head;
		printf("The elements are::\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}
void insertfront()
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node*)); 
	int item;
	printf("\nEnter the element: ");
	scanf("%d",&item);
	new->data = item;
	new->link = head;
	head=new;
	printf("SUCCESFULLY INSERTED.\n");	 
} 

void insertrear()
{
	struct node *new,*ptr;
	new=(struct node*)malloc(sizeof(struct node*)); 
	int item;
	printf("\nEnter the element: ");
	scanf("%d",&item);
	new->data = item;
	new->link=NULL;
	if(head==NULL)
	{
		head = new;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
		
	}
	printf("SUCCESFULLY INSERTED.\n");
}

void insertafter()
{
	struct node *new,*ptr;
	
	int item,se;
	
	printf("Enter the element after which item should be inserted: ");
	scanf("%d",&se);
	
	if(head==NULL)
	{
		printf("EMPTY LIST!!!");
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL && ptr->data!=se)
		{
			ptr=ptr->link;
		}
		if(ptr->data!= se)
		{
			printf("Insertion not possible.");
		}
		else
		{
			new=(struct node*)malloc(sizeof(struct node*)); 
			printf("\nEnter the element: ");
			scanf("%d",&item);
			new->data = item;
			new->link=ptr->link;
			ptr->link=new;
			printf("SUCCESFULLY INSERTED.\n");
		}
		
		
	}
}

void deletefront()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("EMPTY LIST!!!");
	}
	else
	{
		temp=head;
		head=head->link;
		free(temp);
		printf("Succesfully deleted.");
	}
}

void deleterear()
{
	struct node *temp,*prev,*curr;
	if(head==NULL)
	{
		printf("EMPTY LIST!!!, insertion not possible.");
	}
	else if(head->link==NULL)
	{
		temp =head;
		head=NULL;
		free(temp);
		printf("SUCCESFULLY DELETED..\n");
	}
	else
	{
		prev=head;
		curr=head->link;
		while(curr->link!= NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		prev->link=NULL;
		free(curr);
		printf("SUCCESFULLY DELETED..\n");
		
	}
}

void deletespecific()
{
	struct node *temp,*prev,*curr;
	int se;
	
	printf("Enter the element to be deleted: ");
	scanf("%d",&se);
	if(head==NULL)
	{
		printf("EMPTY LIST!!!");
	}
	else if(head->link==NULL & head->data == se)
	{
		temp=head;
		head=NULL;
		free(temp);
		printf("SUCCESFULLY DELETED..\n");
	}
	else
	{
		prev=head;
		curr=head;
		while(curr->data!= se && curr->link!=NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		if(curr->data != se)
		{
			printf("DELETION NOT POOSIBLE!!!\nElement not found.");
		}
		else
		{
			prev->link=curr->link;
			free(curr);
			printf("SUCCESFULLY DELETED..\n");
		}
	}
}

int main()
{
	int op;
	printf("                Singly linked list operations.\n");
	while(1)
	{
		printf("\n        ++++++++++++++++++++++MENU+++++++++++++++++++++++++\n<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>\n<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete specific ~~>>\n                   <<7.display ~~ 8.exit >>\n");
		printf("\nEnter your option: ");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:
			insertfront();
			break;
			case 2:
			insertrear();
			break;
			case 3:
			insertafter();
			break;
			case 4:
			deletefront();
			break;
			case 5:
			deleterear();
			break;
			case 6:
			deletespecific();
			break;
			case 7:
			display();
			break;
			case 8:
			exit(1);
			
		}
	}
	
	
}

/*
                Singly linked list operations.
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 1

Enter the element: 23
SUCCESFULLY INSERTED.
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 2

Enter the element: 34
SUCCESFULLY INSERTED.
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 3
Enter the element after which item should be inserted: 23

Enter the element: 333
SUCCESFULLY INSERTED.
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 7
The elements are::
23
333
34
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 6
Enter the element after which item should be deleted: 333
SUCCESFULLY DELETED..
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 4
Succesfully deleted.        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 5
SUCCESFULLY DELETED..
        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 7
LIST EMPTY!!!        ++++++++++++++++++++++MENU+++++++++++++++++++++++++
<< 1.insert at front ~~   2.insert at rear  ~~  3.insert after ~~ >>
<< 4.delete from front ~~ 5.delete from rear ~~ 6. delete after ~~>>
                   <<7.display ~~ 8.exit >>

Enter your option: 8

*/


