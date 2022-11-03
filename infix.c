#include <stdio.h>
#include <string.h>

int top=-1;
char infix[100],post[100],stack[100];

void push(char item)
{
	top=top+1;
	stack[top]=item;
}

char pop()
{
	char temp = stack[top];
	top=top-1;
	return temp;
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

int main()
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
}
