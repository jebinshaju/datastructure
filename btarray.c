#include<stdio.h>
#include <stdlib.h>
int flag =0,ret_ser =0,a[100],size;

void buildtree(int i,int item)
{
	int op;
	int data;
	a[i]=item;
	printf("Is %d having  a left child? [1/0] :: ",item);
	scanf("%d",&op);
	if(op==1)
	{
		printf("Enter the element:: ");
		scanf("%d",&data);
		buildtree(2*i,data);
	}
	else
	{
		printf("ok!!!🙄\n");
	}
	printf("Is %d having  a right child? [1/0] :: ",item);
	scanf("%d",&op);
	if(op==1)
	{
		printf("Enter the element:: ");
		scanf("%d",&data);
		buildtree(2*i+1,data);
	}
	else
	{
		printf("ok!!!🙄\n");
	}
	
}

void display()
{
	int i;
	for(i=1;i<size;i++)
	{
		if(a[i]==0)
		{
			printf(" - ");
		}
		else
		{
			printf(" %d ",a[i]);
		}
	}
	printf("\n");
}

void search_seq(int i,int key)
{
	if(flag==0)
	{
		if(a[i]==key)
		{
			flag=1;
			ret_ser=i;
		}
		else
		{
			if(2*i<=size)
			{
				search_seq(2*i,key);
			}
			if(2*i+1<=size)
			{
				search_seq(2*i+1,key);
			}
		}
	}
}


void insertion(int key,int item)
{
	int op,i;
	search_seq(1,key);
	i=ret_ser;
	if(i==0)
	{
		printf("Unsuccesful search\n");
	}
	else
	{
		if(a[2*i]==0 || a[2*i+1]==0)
		{
			printf("Is %d having  a left or right child? [1/0] :: ",a[i]);
			scanf("%d",&op);
			if(op==1)
			{
				if(a[2*i]==0)
				{
					a[2*i]=item;
					printf("Succesfully inserted...\n");
				}
				else
				{
					printf("Insertion not possible as left child..\n");
				}
			}
			else if(op==0)
			{
				if(a[2*i+1]==0)
				{
					a[2*i+1]=item;
					printf("Succesfully inserted...\n");
				}
				else
				{
					printf("Insertion not possible as right child..\n");
				}
			}
			else
			{
				printf("Invalid option!!! \n");
			}
		}
		else
		{
			printf("Insertion not possible as it is having 2 children...\n");
		}
	}
}

void deletion(int item)
{
	int i;
	search_seq(1,item);
	i=ret_ser;
	if(i==0)
	{
		printf("No such data in tree!!! \n");
	}
	else
	{
		if(a[2*i]==0 && a[2*i+1]==0)
		{
			a[i]=0;
			printf("Succesfully deleted...\n");
		}
		else
		{
			printf("Deletion not possible as leaf node!!! \n");
		}
	}

}


int main()
{
	int op,root,item,key,i;
	printf("Binary tree using array\n");
	printf("Enter the size of array:: ");
	scanf("%d",&size);
	
	for(i=0;i<size;i++)
	{
		a[i]=0;
	}
	
	printf("Enter the root node: ");
	scanf("%d",&root);
	buildtree(1,root);
	display();
	
	while(1)
	{
		printf("<< 1.Insert - 2.Deletion - 3.Search - 4.Display - 5.Exit >>");
		printf("Enter your option:: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter the item:: ");
			scanf("%d",&item);
			printf("Enter the parent node::");
			scanf("%d",&key);
			insertion(key,item);
			break;
			
			case 2:
			printf("enter the item to be deleted:");
			scanf("%d",&item);
			flag=0;
			deletion(item);
			break;
			
			case 3:
			
			printf("Enter the key:: ");
			scanf("%d",&item);
			search_seq(1,item);
			if(ret_ser == 0)
			{
				printf("Unsuccesful search!!!..\n");
			}
			else
			{
				printf("Element found...\n");
			}
			break;
			
			case 4:
			display();
			break;
			
			case 5:
			exit(1);
			
			default:
			printf("Invalid option");
			
			
			
		}
	}
	
}
