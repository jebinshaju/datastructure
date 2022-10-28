#include<stdio.h>
void readmatrix(int arr[40][40],int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("Enter the element [%d][%d]: ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
}

void display(int arr[40][40],int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			
			printf("%d  ",arr[i][j]);
		}
		printf("\n\n");
	}
}

int tuple(int arr[40][40],int r,int c,int tup[40][40])
{
	int k=1,i,j;
	tup[0][0]=r;
	tup[0][1]=c;
	
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if (arr[i][j]!=0)
			{
			
				tup[k][0]=i;
				tup[k][1]=j;
				tup[k][2]=arr[i][j];
				k++;
			}
		}
	}
	tup[0][2]=k-1;
	return k;
}

int transpose(int arr[40][40],int tra[40][40])
{
	int k=1,i,j;
	tra[0][0]=arr[0][1];
	tra[0][1]=arr[0][0];
	tra[0][2]=arr[0][2];
	
	for(i=0;i<arr[0][1];i++)
	{
		for (j=1;j<=arr[0][2];j++)
		{
			if (arr[j][1]==i) //
			{
				tra[k][0]=arr[j][1];
				tra[k][1]=arr[j][0];
				tra[k][2]=arr[j][2];
				k=k+1;
			}
		}
	}
	return k;
}

void main()
{
	int r,c,arr[40][40],tup[40][40],tra[40][40];
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of columns: ");
	scanf("%d",&c);
	
	printf("Enter the matrix: \n\n");
	readmatrix(arr,r,c);
	printf("The matrix is\n");
	display(arr,r,c);
	
	int k=tuple(arr,r,c,tup);
	printf("The tuple matrix is\n\n");
	display(tup,k,3);
	
	int k2=transpose(tup,tra);
	printf("The transpose of tuple matrix is\n\n");
	display(tra,k,3);
}
