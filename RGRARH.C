#include<stdio.h>
#include<conio.h>
int a[60],m[23][55],n,top=-1,stack[89],front=-1,rear=-1,q[99];
void insert();
void D_first();
void push(int );
int pop();
void B_first();
void enqueue(int );
int dequeue();
int main()
{
     int ch,y;
     insert();
     do
     {
              printf("\n\nmenu\n\n");
              printf("1.breadth first search\n");
              printf("2.depth first search\n");
              printf("3.exit\n");
              printf("Enter ur choice\n");
              scanf("%d",&ch);
              switch(ch)
              {
                        case 1:
                             printf("\nBreadth First traversal\n");
                             B_first();
                             break;
                        case 2:
                             printf("\nDepth First traversal\n");
                             D_first();
                             break;
                        default:
                                printf("Enter the right choice\n");
                                break;
              }
              printf("\nDo u want to continue1/0");
              scanf("%d",&y);
     }while(y==1);
     getch();
}
void insert()
{
     int i,j,item;
     int cho;
     printf("Enter the no of vertices\n");
     scanf("%d",&n);
     printf("Enter the vertices\n");
     for(i=0;i<n;i++)
                     scanf("%d",&a[i]);
     for(i=0;i<n;i++)
     {
           for(j=0;j<=n;j++)
                            m[i][j]=0;
     }
     for(i=0;i<n;i++)
     {
          printf("\ndo u want adjacent node for %d (1/0) : ",a[i]);
          scanf("%d",&cho);
          while(cho==1)
          {
                 printf("\nEnter the adjacent node:");
                 scanf("%d",&item);
                 for(j=0;j<n;j++)
                 {
                        if(a[j]==item)
	                       break;
                 }
                 m[i][j]=1;
         printf("\nDo u want more nodes for %d (1/0) : ",a[i]);
         scanf("%d",&cho);
                     }
     }
     printf("\nAdjacency Matrix\n");
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                               printf("%d ",m[i][j]);
                     }
                     printf("\n");
     }      
}

void D_first()
{
     int visit[67],loc,i,j,k,tmp;
     for(i=0;i<n;i++)
                     visit[i]=0;

     push(a[0]);
     while(top!=-1)
     {
	               tmp=pop();
                   for(loc=0;loc<n;loc++)
	               {
                           if(a[loc]==tmp)
                                break;
                   }
	               if(visit[loc]==0)
	                               printf("%d ",a[loc]);
                   visit[loc]=1;
	               for(k=0;k<n;k++)
	               {
                        if((m[loc][k]==1)&&visit[k]==0)
	                    {
	                         push(a[k]);
                        }
                   }
     }
}
int pop()
{
    int item;
    item=stack[top];
    top=top-1;
    return item;
}
void push(int item)
{
     top=top+1;
     stack[top]=item;
}


void B_first()
{
     int visit[67],loc,i,j,k,tmp;
     for(i=0;i<n;i++)
     {
                     visit[i]=0;
     }
     enqueue(a[0]);
     while(front!=-1)
     {
                     tmp=dequeue();
                     for(loc=0;loc<n;loc++)
                     {
                                           if(a[loc]==tmp)
                                                          break;
                     }
	                 if(visit[loc]==0)
	                             printf("%d ",a[loc]);
                     visit[loc]=1;
                     for(k=0;k<n;k++)
	                 {
                              if(m[loc][k]==1&&visit[k]==0)
	                          {
	                               enqueue(a[k]);
                              }
	                 }
     }
}
void enqueue(int item)
{
     if(rear==-1)
            front=0;
     rear=rear+1;
     q[rear]=item;
}
int dequeue()
{
    int item;
    item=q[front];
    if(front==rear)
    {
          front=-1;
          rear=-1;
    }
    else
          front=front+1;
    return item;
}
