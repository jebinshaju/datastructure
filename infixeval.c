#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int top=-1,s1[100],c[100];
char infix[100],post[100],stack[100];

void push(char item)
{
	top=top+1;
	stack[top]=item;
}

void push1(int item)
{
	top++;
	s1[top]=item;
}

char pop()
{
	char temp = stack[top];
	top=top-1;
	return temp;
}

int pop1()
{
	int item=s1[top];
	top--;
	return item;
}

int prio(char item)
{
	if(item =='+'|| item =='-')
		return 1;
	else if(item =='*' || item == '/')
		return 2;
	else if(item == '^')
		return 3;
	else
		return 0;
}

int operate(int a, int b, char c)
{
	int fact=1,i;
	if(c=='+')
	{
		return(a+b);
	}
	else if(c=='-')
	{
		return(a-b);
	}
	else if(c=='*')
	{
		return(a*b);
	}
	else if(c=='/')
	{
		return(a/b);
	}
	else if(c=='^')
	{
		for(i=0;i<b;i++)
		{
			fact=fact*i;
		}
		return(fact);
	}
	else
	{
		return 0;
	}
}
int expression()
{
	int i=0,j=0;
	char item;
	printf("Enter the infix expression: ");
	gets(infix);
	
	while(infix[i] != '\0')
	{
		if(isalpha(infix[i]))
		{
			post[j]=infix[i];
			j++;
			
		}
		else if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				item = pop();
				post[j]=item;
				j++;
			}
			pop();
		}
		else
		{
			if(prio(infix[i]) > prio(stack[top]))
			{
				push(infix[i]);
			}
			else
			{
				while(prio(infix[i]) <= prio(stack[top]) && top!=-1)
				{
					item =pop();
					if(item!='(' || item !=')')
					{
						post[j]=item;
						j++;
					}
				
				}
			}
		}
		i++;
		
	}
	while(top!=-1)
	{
		post[j]=pop();
		j++;
	}
	printf("The postfix expression is %s \n",post);
	return j;
}

void evaluation(int j)
{
	int i=0,m=0;
	while(top!=-1)
	{
		post[j]=pop();
		j++;
	}
	printf("Postfix expression : %s\n\n",post);

	for(i=0;i<j;i++)
	{
		if(isalpha(post[i])!=0)
		{
			printf("Enter the value for %c : ",post[i]);
			scanf("%d",&c[i]);
			m++;
		}
	}
	printf("Post fix experssion with value: ");
	m=0;
	for(i=0;i<j;i++)
	{
		if(isalpha(post[i])!=0)
		{
			printf("%d",c[m]);
			m++;
		}
		else
		{
			printf("%c",post[i]);
		}
	}
	i=0;
	m=0;
	while(i<j)
	{
		if(isalpha(post[i])!=0)
		{
			push1(c[m]);
			m++;
		}
		else
		{
			int y=pop1();
			int x=pop1();
			int z=operate(x,y,post[i]);
			push1(z);
		}
		i++;
	}
	printf("\n\nThe final result of the experssion: %d",pop1());
	
}


int main() 
{
	int j=expression();
	evaluation(j);
}

/*
Enter the infix expression: (a+b)*(c-d)
The postfix expression is ab+cd-*
Postfix expression : ab+cd-*

Enter the value for a : 1
Enter the value for b : 2
Enter the value for c : 3
Enter the value for d : 4
Post fix experssion with value: 12+03-*

The final result of the experssion: -9
*/
