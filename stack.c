#include<stdio.h>
#include<stdlib.h>

int top=-1,size=5,stack[20];
void push(int item)
{
	if(top==size-1)
	{
		printf("The stack is full.");
	}
	else
	{
		top++;
		stack[top]=item;
		printf("Sucessfully pushed.\n");
	}
}
int pop()
{
	if(top==-1)
	{
		printf("The stack is empty.");
	}
	else
	{
		printf("Item poped is %d",stack[top]);
		top=top-1;
	}
}
void status()
{
	float free;
	if(top==-1)
	{
		printf("The stack is empty.");
	}
	
	else if(top==size-1)
	{
		printf("The stack is full.");
	}
	
	else
	{
		free = ((size-top-1)*100)/size;
		printf("space available is %.2f percent.",free);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("The stack is empty.");
	}
	
	else 
	
	{
		for(i=top;i>=0;i--)
		{
			printf("\nElement at %d -> %d",i,stack[i]);
		}
	}
}
int main()
{
	int op,item;
	printf("Stack operations.\n");
	printf("Enter the size :: ");
	scanf("%d",&size);
	while(1)
	{
		printf("\n1.push\n2.pop\n3.display\n4.status\n5.exit\nEnter your option:: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nEnter the item to be pushed: ");
				scanf("%d",&item);
				push(item);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				status();
				break;
				
			case 5:
				printf("Exiting>>>");
				exit(1);
				
			default:
				printf("Enter a valid option");
				
		}
	}
}
