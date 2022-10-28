#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,size=5;

struct prioqueue
{
	int item,priority;
}a[20];

void enqueue()
{
	int itm,prio;
	int i;
	if(front==0 && rear== size-1)
	{
		printf("\nThe queue is full!!!");
	}
	else if(front==-1 && rear== -1)
	{
		printf("\nEnter the item to be Enqueued: ");
		scanf("%d",&itm);
		printf("Enter the priority: ");
		scanf("%d",&prio);
		front=0;
		rear=0;
		a[rear].item=itm;
		a[rear].priority=prio;
	}
	else if(rear==size-1)
	{
		printf("\nEnter the item to be Enqueued: ");
		scanf("%d",&itm);
		printf("Enter the priority: ");
		scanf("%d",&prio);
		for(i=front;i<=rear;i++)
		{
			a[i-1].item=a[i].item;
			a[i-1].priority=a[i].priority;
		}
		front=front-1;
		rear=rear-1;
		for(i=rear;i>=front;i--)
		{
			if(a[i].priority<prio)
			{
				break;
			}
		}
		int loc=i+1;
		for(i=rear;i>=loc;i--)
		{
			a[i+1].priority=a[i].priority;
			a[i+1].item=a[i].item;
		}
		a[loc].item=itm;
		a[loc].priority=prio;
		rear=rear+1;
	}
	else
	{
		printf("\nEnter the item to be Enqueued: ");
		scanf("%d",&itm);
		printf("Enter the priority: ");
		scanf("%d",&prio);
		for(i=rear;i>=front;i--)
		{
			if(a[i].priority<prio)
			{
				break;
			}
		}
		int loc=i+1;
		for(i=rear;i>=loc;i--)
		{
			a[i+1].priority=a[i].priority;
			a[i+1].item=a[i].item;
		}
		a[loc].item=itm;
		a[loc].priority=prio;
		rear=rear+1;
		
	}
}

void dequeue()
{
	if(front==-1 && rear== -1)
	{
		printf("\nThe queue is empty.");
	}
	else if(front==rear)
	{
		printf("\nThe dequed item is %d",a[front].item);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\nThe dequed item is %d",a[front].item);
		front=front+1;
	}
}

void display()
{
	int i;
	if(front==-1 && rear== -1)
	{
		printf("\nThe queue is empty.");
	}
	else
	{
		printf("\nThe elements are:");
		for(i=front;i<=rear;i++)
		{
			printf(" %d  ",a[i].item);
		}
		printf("\n");
	}
}

int main()
{
	int op;
	printf("                   Priority Queue Operations.\n");
	printf("Enter the size: ");
		scanf("%d",&size);
	while(1)
	{
		printf("\n<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>>  \n\nEnter your option:: ");
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

/*
                   Priority Queue Operations.
Enter the size: 5
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>>  

Enter your option:: 1

Enter the item to be Enqueued: 12
Enter the priority: 33

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 1

Enter the item to be Enqueued: 4
Enter the priority: 23

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 3

The elements are: 4   12  

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 1

Enter the item to be Enqueued: 24
Enter the priority: 455

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 3

The elements are: 4   12   24  

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 1

Enter the item to be Enqueued: 234
Enter the priority: 2

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 1

Enter the item to be Enqueued: 24
Enter the priority: 14

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 1

The queue is full!!!
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 3 

The elements are: 234   24   4   12   24  

<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The dequed item is 234
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The dequed item is 24
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The dequed item is 4
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The dequed item is 12
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The dequed item is 24
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 2

The queue is empty.
<<<<< 1.Enqueue ~~~ 2.Dequeue ~~~ 3.display ~~~ 4.exit >>>>> (size=5) 

Enter your option:: 4
Exiting>>>
*/
