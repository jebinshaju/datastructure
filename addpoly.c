#include<stdio.h>
struct poly
{
	int coef;
	int expo;
}p1[20],p2[20],p3[20];

int readpoly(struct poly p[])
{
	int t,i;
	printf("Enter the number of terms :: ");
	scanf("%d",&t);
	printf("\n");
	for(i=0;i<t;i++)
	{
		printf("Coefficient of term %d : ",1+i);
		scanf("%d",&p[i].coef);
		printf("Exponent of term %d : ",i+1);
		scanf("%d",&p[i].expo);
	}
	return t;
}

void display(struct poly p[],int t)
{
	int i;
	printf("\n");
	for(i=0;i<t-1;i++)
	
	{
		printf("%dx^%d + ",p[i].coef,p[i].expo);
		
	}
	printf("%dx^%d\n\n",p[t-1].coef,p[t-1].expo);
}

int addpoly(struct poly p1[],struct poly p2[],int t1,int t2,struct poly p3[])
{
	int i=0,j=0,k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			p3[k].coef=p1[i].coef + p2[j].coef;
			p3[k].expo=p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k].coef=p1[i].coef;
			p3[k].expo=p1[i].expo;
			i++;
			k++;
		}
		else
		{
			p3[k].coef=p2[j].coef;
			p3[k].expo=p2[j].expo;
			j++;
			k++;
		}
		
	}
	while(i<t1)
	{
		p3[k].coef=p1[i].coef;
		p3[k].expo=p1[i].expo;
		i++;
		k++;
	}
	while(j<t2)
	{
		p3[k].coef=p2[j].coef;
		p3[k].expo=p2[j].expo;
		j++;
		k++;		
	}
	return k;
}

int main()
{
	int t1,t2,t3;

	printf("Enter the first polynomial\n\n");
	t1=readpoly(p1);
	printf("\nThe first polynomial is: ");
	display(p1,t1);
	printf("Enter the second polynomial\n\n");
	t2=readpoly(p2);
	printf("\nThe second polynomial is: ");
	display(p2,t2);
	t3=addpoly(p1,p2,t1,t2,p3);
	printf("\nThe sum of polynomial: ");
	display(p3,t3);
		
}
