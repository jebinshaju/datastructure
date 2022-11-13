#include<stdio.h>

void binary(int arr[],int low,int high)
{
	
	int se,flag=0,mid;
	printf("Enter the search element: ");
	scanf("%d",&se);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==se)
		{
			flag=1;
			break;
		}
		else if (arr[mid]>se)
			high=mid-1;
		else
			low=mid+1;
		
	}
	if(flag==1)
		printf("Element found at index %d.",mid);
	else
		printf("Element not found.");
}

void linear(int arr[],int n)
{
	int se,i,flag=0;
	printf("Enter the serach element: ");
	scanf("%d",&se);
	for(i=0;i<n;i++)
	{
		if (arr[i]==se)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("Element found at index %d.",i);
	else
		printf("Element not found.");
	
}

int main()
{
	int n,arr[30],i,flag=1,op;

	printf("\nEnter the number of elements of array: ");
	scanf("%d",&n);
	printf("Enter the elemnts in ascending order.\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the element A[%d]: ",i);
		scanf("%d",&arr[i]);	
	}

	while(flag==1)
	{
		printf("\n\nEnter 1 to binary search\nEnter 2 to linear search\nEnter 3 to exit\n\nEnter your option:::  ");
		scanf("%d",&op);
		if (op==1)
		{
			binary(arr,0,n-1);
		}
		else if (op==2)
		{
			linear(arr,n);
		}
		
		else if (op==3)
		{
			flag=2;
			break;
		}
		else
			printf("Invalid option\n");
	}	
	return 0;	
}


/*

Enter the number of elements of array: 4
Enter the elemnts in ascending order.
Enter the element A[0]: 1
Enter the element A[1]: 4
Enter the element A[2]: 6
Enter the element A[3]: 8


Enter 1 to binary search
Enter 2 to linear search
Enter 3 to exit

Enter your option:::  1
Enter the search element: 4
Element found at index 1.

Enter 1 to binary search
Enter 2 to linear search
Enter 3 to exit

Enter your option:::  1
Enter the search element: 5
Element not found.

Enter 1 to binary search
Enter 2 to linear search
Enter 3 to exit

Enter your option:::  2
Enter the serach element: 6
Element found at index 2.

Enter 1 to binary search
Enter 2 to linear search
Enter 3 to exit

Enter your option:::  2
Enter the serach element: 7
Element not found.

Enter 1 to binary search
Enter 2 to linear search
Enter 3 to exit

Enter your option:::  3
*/














