#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 10
class park
{
	private:
		char arr[MAX_SIZE+1][10];
		int top;
	public:
		void create();
		void insert();
		void remove();
		void display();
		park();
};

park::park()
{
	top=0;
}

void park::create()
{
	if(top!=0)
	{
		cout<<"Already Created.\n";
		return;
	}
	for(int i=1;i<MAX_SIZE;i++)
	{
		strcpy(arr[++top],"\0");
	}
}

void park::insert()
{
	char cno[10];
	int i=1;
	while(i<=top)
	{
		if(strcmp(arr[i],"\0")==0)
		{
			cout<<"\nEnter Car Number to be parked:";
			cin>>cno;
			strcpy(arr[i],cno);
			cout<<"\nSlot:"<<i;
			cout<<"\nCar Number:"<<arr[i];
			return;
		}
		else
		{
			i++;
		}
	}
	cout<<"Sorry. All the slots are full.\n";
	return;	
}
void park::remove()
{
	int sl;
	int i=0;
	cout<<"\nEnter slot number from which car is to be removed:";
	cin>>sl;
	
    while(i<=top)
	{
		if(i==sl)
		{
	        strcpy(arr[i],"\0");	
	        return;
		}
		i++;
	}
	cout<<"\nEntered slot number is invalid:";
	return;
}

void park::display()
{
	int i=1;
	while(i<=top)
	{
		cout<<"\n---------------------------------------------";
		cout<<"\nSlot:"<<i;
		cout<<"\nAvailability:";
		if(strcmp(arr[i],"\0")!=0)
		{
			cout<<"No";
			cout<<"\nCar Number, parked is:"<<arr[i];
		}
		else
		cout<<"Yes";
		i++;
	}
	cout<<"\n---------------------------------------------";
	return;
}
int main()
{
	int ch1,ch2;
	park obj;
	obj.create();
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
			obj.display();
			break;
		case 2:
			obj.insert();
			break;
		case 3:
			obj.remove();
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

























