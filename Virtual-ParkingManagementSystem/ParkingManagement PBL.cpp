#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<strings.h>
using namespace std;


struct node // Structure for Stack Parking
{
    char data[10];
    struct node *link;
};
struct node *top=NULL,*temp;//Initalisations for StackParking

struct link // Structure for Queue Parking
{
       int info;
       struct link *next;
};
struct link *front=NULL,*rear=NULL,*link=NULL;//Initalisations for Queue Parking

class Parking
{
	
/*	struct node *top=NULL,*temp;//Stack Parking Initalisers   */
	public:
		
	void StackParking();
	void QueueParking();
		
};

void Parking::StackParking()
{
    int choice;
	char data[10];
	int count=0;
	 
    while(1)
    {
    	system("cls");
        cout<<"\n1.Insert Vehicle to Parking Slot\n2.Take Out(PoP) Vehicle from Parking Slot\n4.Display Vechiles Parked in StackParking\n3.Take Out Vehicle in between Parking Slots\n5.Exit\n";
        cout<<"\nEnter Your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        	if(count == 5)
        	{
        		cout<<"\n\n\t\tSorry!Maximum Parking Limit in StackParking Reached\n";
        		getch();
        		exit(0);
        	}
            temp=(struct node *)malloc(sizeof(struct node));
            cout<<"Enter Vehicle Number to be Parked : ";
            cin>>data;
            strcpy(temp->data,data);
            temp->link=top;
            top=temp;
            count++;
            break;
        case 2:
            if(top!=NULL)
            {
                cout<<"The Vehicle removed from ParkingSlots is "<<top->data<<"\n";
                top=top->link;
                count--;
            }
            else
            {
                cout<<"\nStack Parking Slots are Underflow(No Vehicle to Display)";    
            }
            break;
            
        case 3:
            temp=top;
            cout<<"\nVechiles Parked in StackParking are: \n\n";
            if(temp==NULL)
            {
                cout<<"\nSorry!Parking Slots of StackParking are empty\n";
            }
            
            while(temp!=NULL)
            {
                cout<<"-> "<<temp->data<<" ->***";
                temp=temp->link;
            }
            getch();
            break;
        case 4:
            exit(0);
        }
        
    }      
}

void Parking::QueueParking()
{
	  int choice,count=0;
      while(1)
      {
       system("cls");
       cout<<"\n1.Insert Vehicle to Parking Slot\n2.Take Out Vehicle from Parking Slot in Linear Order\n3.Take Out Vehicle from Parking Slot\n4.Display Vechiles Parked in QueueParking\n5.Exit\n";
       cout<<"\nEnter Your choice: ";
       cin>>choice;
       switch(choice)
       {
                    case 1:
                    	if(count == 5)
        	          {
        		       cout<<"\n\n\t\tSorry!Maximum Parking Limit in StackParking Reached\n";
        		       getch();
        		       exit(0);
        	          }
                     struct link *temp;
                     temp=(struct link *)malloc(sizeof(struct link));
                     cout<<"\nEnter Vehicle Number to be Parked :\n";
                     cin>>temp->info;
                     count++;
                     temp->next=NULL;
                    if(front==NULL)
                    {
                    link=temp;
                    front=temp;
                    }
                    if(link!=NULL)
                    {
                    link->next=temp;
                    link=temp;
                    }
                    rear=temp;
                    break;
                    
                    case 2:
                    struct link *temp1;
                    if(front==NULL)
                    {
                     cout<<"\nQUEUE Parking Slots are Underflow(No Vehicle to Display)";
                     break ;
                    }
                     cout<<"The Vehicle removed from ParkingSlots is : "<<front->info<<"\n";
                     getch();
                     count--;
                     temp1=front;
                     front=front->next;
                     free(temp1);
                    break;
                    
                    case 4:
                    if(front==NULL)
                    {
                     cout<<"\nSorry!QUEUE Parking Slots are empty";
                     break;
                    }
                    link=front;
                    while(link!=NULL)
                    {
                     cout<<"\n"<<link->info;
                     link=link->next;
                    }
                    getch();
                    break;
                    
                    case 3:
                      int value;
                      cout<<"\nPlease give vehicle number you want to take out:";
                      cin>>value;
                      struct link *Temp,*DumNode;
                      Temp=front;
                      while(Temp!=NULL)
                      {
                        if(Temp->info == value)//Temp Getting into Required Node of L.L
                        {
                           if(Temp==front)
                           {
                            front=Temp->next;
                            free(Temp);
                            break;
                           }
                           else
                           {
                            DumNode->next=Temp->next;//Formed Required Link.
                            free(Temp);
                            cout<<"\n\nData deleted from list is : "<<value<<" \n\n";
					        getch();
                            break;
                           }
                        }
                        else
                        {
                         DumNode=Temp;//DumNode Points towards last but one element Reg.Temp.
                         Temp=Temp->next;//Traversal
                        }
                       }
                    break;   
                    
                    case 5:
                    exit(0);
                    break;
                    
                    default:
                    cout<<"\n\t\tSorry!Try again";
       }
     }
}


int main()
{
	Parking Project;
	int choice;
	while(1)
	{
	system("cls");
	cout<<"\n1.StackParking\n2.QueueParking\n3.\n0.Exit\n";
	cout<<"Please select the Type of Parking:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			Project.StackParking();
			break;
		case 2:
			Project.QueueParking();
			break;
		case 0:
			exit(0);
	}
    }
	return 0;
}
