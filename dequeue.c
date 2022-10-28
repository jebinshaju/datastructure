#include<stdio.h>
#include<stdlib.h>

int rear=-1,front=-1,size=5,queue[20];

int inject()
{
	int item,i;
	if(front==0 && rear==size-1)
	{
		printf("The queue is full !!!.\n");
	}
	else if(front==-1 && rear==-1)
	{
		printf("\nEnter the item to be injected: ");
		scanf("%d",&item);
		front=0;
		rear=0;
		queue[rear]=item;
		printf("Sucessfully injected.\n");
	}
	else if(rear<size-1)
	{
		printf("\nEnter the item to be injected: ");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
	}
	else
	{
		printf("\nEnter the item to be injected: ");
		scanf("%d",&item);
		for(i=front;i<rear;i++)
		{
			queue[i-1]=queue[i];
		}
		queue[rear]=item;
		front=front-1;
		printf("Sucessfully injected.\n");
	}
}

void eject()
{
	if(front==-1 && rear==-1)
	{
		printf("The queue is empty!!!.\n");
	}
	else if(rear==front)
	{
		printf("The ejected item is %d\n",queue[rear]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("The ejected item is %d\n",queue[rear]);
		rear=rear-1;
	}
}

int push()
{
	int item,i;
	if(front==0 && rear==size-1)
	{
		printf("The queue is full !!!.\n");
	}
	else if(front==-1 && rear==-1)
	{
		printf("\nEnter the item to be pushed: ");
		scanf("%d",&item);
		front=0;
		rear=0;
		queue[front]=item;
		printf("Sucessfully pushed.\n");
	}
	else if(front>0)
	{
		printf("\nEnter the item to be pushed: ");
		scanf("%d",&item);
		front=front-1;
		queue[front]=item;
	}
	else
	{
		printf("\nEnter the item to be pushed: ");
		scanf("%d",&item);
		for(i=rear;i>=0;i--)
		{
			queue[i+1]=queue[i];
		}
		queue[front]=item;
		rear=rear+1;
		printf("Sucessfully pushed.\n");
	}
}

int pop()
{
	if(front==-1 && rear==-1)
	{
		printf("The queue is empty!!!.\n");
	}
	else if(rear==front)
	{
		printf("The poped item is %d\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("The poped item is %d\n",queue[front]);
		front=front+1;
	}
}

int display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty.\n");
	}
	else
	{
		printf("Elements are:\n ");
		for(i=front;i<=rear;i++)
		{
			printf("--> %d \n",queue[i]);
		}
		
	}
}

int main()
{
		int op;
		printf("Double ended queue operations.\n");
		printf("Enter the size: ");
		scanf("%d",&size);
		while(1)
		{
			printf("\n<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> \n\nEnter your option:: ");
			scanf("%d",&op);
			switch(op)
			{
				case 1:
					
					push();
					break;
			
				case 2:
					pop();
					break;
			
				case 3:
					inject();
					break;
					
				case 4:
					eject();
					break;
					
				case 5:
					display();
					break;
				
				case 6:
					printf("Exiting>>>\n");
					exit(1);
				
				default:
					printf("Enter a valid option.");
				
			}
		}
}

/*
Double ended queue operations.
Enter the size: 4

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 1

Enter the item to be pushed: 12
Sucessfully pushed.

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 1

Enter the item to be pushed: 23
Sucessfully pushed.

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 5
Elements are:
 --> 23 
--> 12 

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 3

Enter the item to be injected: 34

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 5
Elements are:
 --> 23 
--> 12 
--> 34 

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 1

Enter the item to be pushed: 342
Sucessfully pushed.

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 5
Elements are:
 --> 342 
--> 23 
--> 12 
--> 34 

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 3
The queue is full !!!.

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 2
The poped item is 342

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 4
The ejected item is 34

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 5
Elements are:
 --> 23 
--> 12 

<<<<< 1.PUSH ~~~ 2.POP ~~~ 3.INJECT ~~~ 4.EJECT ~~~ 5.DISPLAY ~~~ 6.EXIT >>>>> 

Enter your option:: 6
Exiting>>>
*/
