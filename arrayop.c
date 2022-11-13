#include<stdio.h>
int size=30,arr[30];
int insert(int n,int size)
{
	int loc,item,i;
	if (n==size)
	{
		printf("\nThe array is full.\n");
		return n;
	}
	else
	{
		printf("\nEnter the location(index) to insert: ");
		scanf("%d",&loc);
		if(loc<=n-1)
		{
			printf("\nEnter the element to insert: ");
			scanf("%d",&item);		
			for (i=n-1;i>=loc;i--)
			{
				arr[i+1]=arr[i];
			}
			arr[loc]=item;
			printf("Succesfully inserted %d",item);
			n=n+1;
			return n;
		}
		else
		{
			printf("Invalid location");
			return n;
		}
	}	
}

int delete(int n)
{
	int item,i,j,flag=0;
	printf("\nEnter the element to delete: ");
	scanf("%d",&item);
	for (i=0;i<n;i++)
	{
		if(arr[i]==item)
		{
			flag=1;
			break;
		}	
	}
	if (flag==1)
	{
		for (j=i;j<n-1;j++)
		{
			arr[j]=arr[j+1];

		}
		n=n-1;
		printf("Succesfully deleted %d",item);
		return n;
	}
	else
	{
		printf("Element not found,");
		return n;
	}
		
	
}

void display(int n)
{
	int i;
	printf("");
	for (i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}

int main()
{
	int n,i,flag=1,op;
	printf("\nEnter the size of array: ");
	scanf("%d",&size);
	printf("\nInitialise the array...\n");
	printf("\nEnter the number of elements of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element A[%d]: ",i);
		scanf("%d",&arr[i]);	
	}

	while(flag==1)
	{
		printf("\n\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n\nEnter your option:::  ");
		scanf("%d",&op);
		if (op==1)
		{
			n=insert(n,size);
		}
		else if (op==2)
		{
			n=delete(n);
		}
		else if (op==3)
		{
			display(n);
		}
		else if (op==4)
		{
			flag=2;
			break;
		}
		else
			printf("Invalid option\n");
	}	
	return 0;	
	
}














