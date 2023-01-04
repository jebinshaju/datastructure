#include<stdio.h>


int A[10]={0};
int B[10]={0};
void hashing1()
{
	int e,n,r;
	printf("enter the number of elements in the array");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the element %d:",i+1);
		scanf("%d",&e);
		r=e%10;
		A[r]=e;
		
	}
}
void Display(int tab[10])
{
	printf("INDEX\tHASH TABLE\n");
	for(int i=0;i<10;i++)
	{
		printf("%d\t%d\n",i,tab[i]);
	}
}
void search1(int tab[10],int e)
{
	int r;
	r=e%10;
	if(A[r]==e)
		printf("element found at index %d\n",r);
	else
		printf("search was unsuccessful\n");
}
void hashing2()
{
	int e,n,r;
	printf("enter the number of elements in the array");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the element %d:",i+1);
		scanf("%d",&e);
		r=e%10;
		if(B[r]==0 || B[r]==e)
			B[r]=e;
		else
		{
			int j=(r+1)%10;
			while(j!=r)
			{
				if(B[j]==e)
					break;
				else
				{
					if(B[j]==0)
						B[j]=e;
					else
						j=(j+1)%10;
				}
			}
		}
	}	
}
int search2(int tab2[10],int e)
{
	int r,i,j;
	r=e%10;
	if(B[r]==e)
		return r;
	else
	{
		int j=(r+1)%10;
		while(j!=r)
		{
			if(B[j]==e)
				return j;
			else if(B[j]==0)
			{
				printf("Search Unsucessful but new vacant space found");
				B[j]=e;
				return j;
			}
			else
				j=(j+1)%10;
		}
		if(j==r)
		printf("Overflow of stack\n");
	}
	
	return -1;
			
}
		
void main()
{
	int c=0,ch,e,f;
	while(c==0)
	{
		printf("1. Normal hashing\n2. Hashing using linearprobing\n3. Exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				hashing1();
				Display(A);
				printf("enter the element to be searched");
				scanf("%d",&e);
				search1(A,e);
				break;
			}
			case 2:
			{
				int z;
				hashing2();
				Display(B);
				printf("enter the element to be searched");
				scanf("%d",&f);
				z=search2(B,f);
				if(z>0)
					printf("element found at index %d\n",z);
				//else
				//	printf("search unsuccessful\n");
				break;
			}
			case 3:
			{
				c=1;
				break;
			}
			default:
			{
				printf("invalid choice");
				break;
			}
		}
	}
}	


/*
1. Normal hashing
2. Hashing using linearprobing
3. Exit
enter your choice1
enter the number of elements in the array4
enter the element 1:5
enter the element 2:6
enter the element 3:7
enter the element 4:5
INDEX   HASH TABLE
0       0
1       0
2       0
3       0
4       0
5       5
6       6
7       7
8       0
9       0
enter the element to be searched5
element found at index 5
1. Normal hashing
2. Hashing using linearprobing
3. Exit
enter your choice2
enter the number of elements in the array5
enter the element 1:6
enter the element 2:6
enter the element 3:7
enter the element 4:7
enter the element 5:9
INDEX   HASH TABLE
0       0
1       0
2       0
3       0
4       0
5       0
6       6
7       7
8       0
9       9
enter the element to be searched67
Search Unsucessful but new vacant space foundelement found at index 8
1. Normal hashing
2. Hashing using linearprobing
3. Exit
enter your choice3
*/