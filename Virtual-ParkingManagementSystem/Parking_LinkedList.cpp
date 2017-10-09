#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#define MAX_SIZE 10
struct node
{
	int slot;
	int avail;
	char car_no[10];
	node *link;
}*head=NULL,*last,*newnode,*temp;
void getnode()
{
	newnode=new node;
}
void readnode(int n)
{
	newnode->slot=n;
	newnode->avail=1;
	strcpy(newnode->car_no,"\0");
	newnode->link=NULL;
}
void create()
{
	int i;
	if(head!=NULL)
	{
		cout<<"Already Created.\n";
		return;
	}
	for(i=0;i<MAX_SIZE;i++)
	{
		getnode();
		readnode(i+1);
		if(newnode==NULL)
		{
			cout<<"Out of space.\n";
			return;
		}
		if(head==NULL)
		{
		    head=last=newnode;	
		}
		else
		{
			last->link=newnode;
			last=newnode;
		}
	}
}
void insert()
{
	char cno[10];
	temp=head;
	while(temp!=NULL)
	{
		if(temp->avail==1)
		{
			cout<<"\nEnter Car Number to be parked:";
			cin>>cno;
			strcpy(temp->car_no,cno);
			temp->avail=0;
			cout<<"\nSlot:"<<temp->slot;
			cout<<"\nCar Number:"<<temp->car_no;
			return;
		}
		else
		{
			temp=temp->link;
		}
	}
	cout<<"Sorry. All the slots are full.\n";
	return;	
}
void remove()
{
	int sl;
	cout<<"\nEnter slot number from which car is to be removed:";
	cin>>sl;
	temp=head;
    while(temp!=NULL)
	{
		if(temp->slot==sl)
		{
		    temp->avail=1;
	        strcpy(temp->car_no,"\0");	
	        return;
		}
		temp=temp->link;
	}
	cout<<"\nEntered slot number is invalid:";
	return;
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		cout<<"\n---------------------------------------------";
		cout<<"\nSlot:"<<temp->slot;
		cout<<"\nAvailability:";
		(temp->avail)?cout<<"Yes":cout<<"No";
		if(temp->avail==0)
		{
			cout<<"\nCar Number, parked is:"<<temp->car_no;
		}
		temp=temp->link;
	}
	cout<<"\n---------------------------------------------";
	return;
}
int main()
{
	int ch1,ch2;
	create();
	do
	{
	cout<<"\nEnter 1 to display availability of parking lots.\n";
	cout<<"Enter 2 to park a car.\n";
	cout<<"Enter 3 to remove a car from parking.\n";
	cout<<"Enter 0 to exit:\n\n";
	cout<<"Enter your choice:";
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			display();
			break;
		case 2:
			insert();
			break;
		case 3:
			remove();
			break;
		case 0:
			return 0;
		default:
			cout<<"Invalid Choice. Try Again.\n";
			
	}
	cout<<"\n\nDo you wish to cotinue? If yes, enter 1, else enter 0:";
	cin>>ch2;
    }while(ch2==1);
    getch();
	return 0;
}
