#include<stdio.h>
#include<stdlib.h>

int rear=-1,front=-1,size=5,queue[5];

int enqueue()
{
	int item;
	if(rear==size-1)
	{
		printf("The queue is full !!!.\n");
	}
	else if(front==-1 && rear==-1)
	{
		printf("\nEnter the item to be Enqueued: ");
		scanf("%d",&item);
		front=0;
		rear=0;
		queue[rear]=item;
		printf("Sucessfully inserted.\n");
	}
	else
	{
		printf("\nEnter the item to be Enqueued: ");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
		printf("Sucessfully inserted.\n");
	}
}

int dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("The queue is empty!!!.\n");
	}
	else if(rear==front)
	{
		printf("The dequeued item is %d\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("The dequeued item is %d\n",queue[front]);
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
		printf("Elements are: ");
		for(i=front;i<=rear;i++)
		{
			printf("--> %d \n",queue[i]);
		}
		
	}
}

int main()
{
		int op;
		printf("Queue operations.\n");
		while(1)
		{
			printf("\n<<<<< 1.Enqueue === 2.Dequeue === 3.display === 4.exit >>>>> \n\nEnter your option:: ");
			scanf("%d",&op);
			switch(op)
			{
				case 1:
					
					enqueue();
					break;
			
				case 2:
					dequeue();
					break;
			
				case 3:
					display();
					break;
				
				case 4:
					printf("Exiting>>>\n");
					exit(1);
				
				default:
					printf("Enter a valid option.");
				
			}
		}
}
