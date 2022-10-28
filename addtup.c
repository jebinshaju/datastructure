#include<stdio.h>
#include <stdlib.h>


void display(int arr[40][40],int r,int c)
{
	int i,j;
	printf("\n");
	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d  ",arr[i][j]);
		}
	printf("\n");
	}
}

int tuple(int arr[40][40],int tup[40][40],int r,int c)
{
	printf("\nTuple Matrix\n");
	int k=1,i,j;
	tup[0][0]=r;
	tup[0][1]=c;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j] != 0)
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

int addtup(int tup1[40][40],int tup2[40][40],int sumtup[40][40])
{
	int r1=tup1[0][0],r2=tup2[0][0],c1=tup1[0][1],c2=tup2[0][1],i,j,k=1,m=1,n=1;
	
	if(r1==r2 && c1==c2)
	{
		sumtup[0][0]=r1;
		sumtup[0][1]=c1;
		
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				if(tup1[m][0]==i && tup1[m][1]==j && tup2[n][0]==i && tup2[n][1]==j)
				{
					sumtup[k][0]=tup1[m][0];
					sumtup[k][1]=tup1[m][1];
					sumtup[k][2]=tup1[m][2]+tup2[n][2];
					k++;
					m++;
					n++;
				}
				else if(tup1[m][0]==i && tup1[m][1]==j)
				{
					sumtup[k][0]=tup1[m][0];
					sumtup[k][1]=tup1[m][1];
					sumtup[k][2]=tup1[m][2];
					k++;
					m++;
				}
				else if(tup2[n][0]==i && tup2[n][1]==j)
				{
					sumtup[k][0]=tup2[n][0];
					sumtup[k][1]=tup2[n][1];
					sumtup[k][2]=tup2[n][2];
					k++;
					n++;
				}
			}
		}
		sumtup[0][2]=k-1;
		return k;
	
	}
	else
	{
		printf("Addition is not possible.");
		exit(0);
	}
}

int main()
{
	int arr1[40][40],arr2[40][40],tup1[40][40],tup2[40][40],sumtup[40][40],i,j,k,m,r1,r2,c1,c2;
	
	printf("Sparse matrix addition.\n");
	printf("Enter the first matrix:\n");
	printf("\nEnter the number of rows: ");
	scanf("%d",&r1);
	printf("\nEnter the number of columns: ");
	scanf("%d",&c1);
	
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("Enter the element[%d][%d]: ",i,j);
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("The first matrix\n");
	display(arr1,r1,c1);
	int x= tuple(arr1,tup1,r1,c1);
	display(tup1,x,3);
	
	printf("\nEnter the second matrix:\n");
	printf("\nEnter the number of rows: ");
	scanf("%d",&r2);
	printf("\nEnter the number of columns: ");
	scanf("%d",&c2);
	
	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("Enter the element[%d][%d]: ",i,j);
			scanf("%d",&arr2[i][j]);
		}
	}
	printf("The second matrix\n");
	display(arr2,r2,c2);
	int y= tuple(arr2,tup2,r2,c2);
	display(tup2,y,3);
	
	int w= addtup(tup1,tup2,sumtup);
	printf("\nThe sum of tuple matrix.\n");
	display(sumtup,w,3);
	
	return 0;
}
