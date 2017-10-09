#include<iostream>
using namespace std;
#include<stdlib.h>
#include<strings.h>

struct node
{
	int data;
    char car[3];
    struct node *link;
};

int Delete_Middle(int value)
            {
	         node *Temp,*DumNode;
               Temp=top;
               while(Temp!=NULL)//Getting into Traversal.
               {
                  if(Temp->data == value)//Temp Getting into Required Node of L.L
                   {
                  if(Temp==top)//Initial Condition.
                    {
                     Head=Temp->link;//i.e Head=NULL
                     free(Temp);
                     return 0;
                     }
                   else
                    {
                     DumNode->link=Temp->link;//Formed Required Link.
                     free(Temp);//Freeing Taken Out Node.
                     printf("\n\nCar taken  out from list is : %d  \n\n",value);
					 getch();
                     return 0;
                    }
                   }
                   else
                  {
                     DumNode=Temp;//DumNode Points towards last but one element Reg.Temp.
                     Temp=Temp->link;//Traversal
                   }
               }
            }
            
            

class Parking
{
	struct node *top=NULL,*temp;
	
	public:
	void Process1();
}

void Parking::Process1()
{

    int choice,data;
    
    
    while(1)//infinite loop is used to insert/delete infinite number of nodes
    {
        
        cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout<<"\nEnter ur choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp=(struct node *)malloc(sizeof(struct node));
            printf("Enter a node data :");
            scanf("%d",&data);
            temp->data=data;
            temp->link=top;
            top=temp;
            break;
        case 2:
           /* if(top!=NULL)
            {
                printf("The poped element is %d",top->data);
                top=top->link;
            }
            else
            {
                printf("\nStack Underflow");    
            }
            break;*/
            int value;
            cout<<"Pls enter car number you want to take out:";
            cin>>value;
            car= Delete_Middle(int value)
             
            
        case 3:
            temp=top;
            if(temp==NULL)
            {
                printf("\nStack is empty\n");
            }
            
            while(temp!=NULL)
            {
                printf("->%d->",temp->data);
                temp=temp->link;
            }
            break;
        case 4:
            exit(0);
        }
        
    }      	
}

int main()
{
	return 0;
}
