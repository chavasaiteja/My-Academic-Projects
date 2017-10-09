#include<iostream>
using namespace std;
#include<stdlib.h>
#include<strings.h>

struct node
{
	//char id[10];//we can use it as floor number and car number
	string id;
	node *floor;//link for other nodes one by one.
	node *slots;//For Edge link.
};

void ParkingBuilding();
void AddVehicle();
void Display();
void RemoveVehicle();

struct node *first,*newnode,*plinker,*elinker,*tempry;

int n,i,x=0,j,nov;

string a;
string b;

int main()
{
	int ch;
	while (1)
		 {      system("cls");
                cout<<"\n1. Make Parking Building\n2. Parking of Vehicle\n3. Unparking of Vehicle";
                cout<<"\n4. Display of Parking Lots\n5. Exit\n";
                cout<<"Enter your choice:";
                cin>>ch;
                switch (ch) 
				{
                        case 1:
                                ParkingBuilding();
                                system("pause");
                                break;

                        case 2:
                                AddVehicle();
                                system("pause");
                                break;

                        case 3:
                                RemoveVehicle();
                                system("pause");
                                break;
                        case 4:
                        	    system("cls");
                                Display();
                                system("pause");
                                break;
                        case 5:
                                exit(0);
                        default:
                                cout<<"Soory!You have entered wrong option!!\n";
                                break;
                }
        }

	return 0;
}

void ParkingBuilding()
{
cout<<"How many floors are there? : ";
cin>>n;
cout<<"Enter all the floor numbers:\n";

 for(i=1;i<=n;i++)
 {
	if(x==0)//Creating first node or root for total building
	{
		newnode = new node;
		cin>>newnode->id;
		first=newnode;//always used to reffered to root floor
		plinker=newnode;//used to create links for one after other nodes by links
		newnode->floor=NULL;
		newnode->slots=NULL;
		x++;//Next nodes	
	}
	else
	{
		//-------------------------//
		newnode = new node;
		cin>>newnode->id;
		newnode->floor=NULL;
		newnode->slots=NULL;
		//------------------------//
		plinker->floor=newnode;
		plinker = newnode;
	}
 }	
}


void AddVehicle()
{

cout<<"Pls give max possible vehicles can be parked:\n";
cin>>nov;//max possible no. of  vehicles
cout<<"\nEnter the vehicle corresponding to floor . Enter a b, where a = floor number and b = vehicle number\n";
cout<<"\nNote:Enter 0 0 if over\n";

 for(j=1;j<=nov;j++)
 {
	cin>>a>>b;
	/*if(strcmp(a,"break") == 0)
	{
	break;
    } */
	plinker = first;
/*%*/while(plinker != NULL && plinker->id != a)//This while loop will take Plinker to perticular required floor
	{
		
		//cout<<"OK";
		plinker=plinker->floor;
	}
	if(plinker == NULL)
	{
		cout<<"Sorry! No floor available in the building \n";
		break;
	}
//-------------------------------------------------------------------------//
	elinker = plinker;
	while(elinker->slots != NULL)//This will take edge link to last
	{
	 elinker = elinker->slots;
    }
	newnode = new node;
	newnode->id=b;
	elinker->slots = newnode;
	newnode->floor=NULL;
	newnode->slots=NULL;
 }	
}

void RemoveVehicle()
{
cout<<"\nEnter the vehicle to be unparked corresponding to floor . Enter a b, where a = floor number and b = vehicle number to be removed\n";
	cin>>a>>b;
	/*if(strcmp(a,"break") == 0)
	{
	break;
    } */
	plinker = first;
/*%*/while(plinker != NULL && plinker->id != a)//This while loop will take Plinker to perticular required floor
	{
		
	//	cout<<"OK";
		plinker=plinker->floor;
	}
	if(plinker == NULL)
	{
		cout<<"Sorry! No floor available in the building \n";
	}
	
//-------------------------------------------------------------------------//

	elinker = plinker;
	
	while(elinker->id != b )//This will take edge link to last
	{
	 tempry = elinker;
	 elinker = elinker->slots;
    }
    
    free(elinker);
    tempry->floor=NULL;
    tempry->slots=NULL;
    
/*	newnode = new node;
	newnode->id=b;
	elinker->slots = newnode;
	newnode->floor=NULL;
	newnode->slots=NULL; */	
}

void Display()
{
	cout<<"\nVehicles parking position display in ParkingBuilding is : \n\n";
	plinker = first;
	while(plinker != NULL)
	{
		cout<<plinker->id<<" ---->"<<"\t";
		elinker = plinker->slots;
		while(elinker != NULL)
		{
			cout<<elinker->id<<"  -->"<<"\t";
			elinker = elinker->slots;
		}
		cout<<"||||\n";
		cout<<"\n";
		plinker = plinker->floor;
	}
}
