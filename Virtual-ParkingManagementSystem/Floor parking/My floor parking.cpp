#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip> 

  struct FloorParking 
  {
        struct Floor *head; // Each Head of Each floor
        int count;
  };

  struct Floor 
  {
  	    int key;
        char name[10];
        struct Floor *next;
  };
  
  typedef struct Floor Floor;
  typedef struct FloorParking FloorParking;
  
  FloorParking *ParkingTable = NULL;
  int CarCount = 0;
  
  Floor * CreateFloor(int key, char *car) 
  {
        Floor *newnode;
        newnode = (Floor *)malloc(sizeof(Floor));
        newnode->key = key;
        strcpy(newnode->name,car);
        newnode->next = NULL;
        return newnode;
  }

   void InsertToFloorParking(int key, char *car) 
   {
        int CarIndex = key % CarCount;
        Floor *newnode =  CreateFloor(key, car);
        /* head of floor list for the floor set with index "CarIndex" */
        if (!ParkingTable[CarIndex].head) //ParkingTable okavela kaliga untae...
		{
                ParkingTable[CarIndex].head = newnode;
                ParkingTable[CarIndex].count = 1;
                return;
        }
        /* adding new car to the floor */ /* [newnode] ----> [oldnode] */
        newnode->next = (ParkingTable[CarIndex].head);
        /*
          update the head of the list and no of nodes in the current floor
         */
        ParkingTable[CarIndex].head = newnode;
        ParkingTable[CarIndex].count++;
        return;
  }
  
  
      void DeleteFromFloorParking(int key)
      {
        // find the Floor using car index 
        int CarIndex = key % CarCount, flag = 0;
        Floor *temp, *myNode;
        // get the list head from current Floor
        myNode = ParkingTable[CarIndex].head;
        if (!myNode) 
		{
                cout<<"\n\tGiven Vehicle is not present in Parking!!\n";
                return;
        }
        temp = myNode;
        while (myNode != NULL)
		 {
                // delete the vehicle with given key 
                if (myNode->key == key) {
                        flag = 1;
                        if (myNode == ParkingTable[CarIndex].head)
                                ParkingTable[CarIndex].head = myNode->next;
                        else
                                temp->next = myNode->next;

                        ParkingTable[CarIndex].count--;
                        free(myNode);
                        break;
                }
                temp = myNode;
                myNode = myNode->next;
        }
        if (flag)
            cout<<"\n\tVehicle  Successfully unparked from Parking Slots!!!\n";
        else
            cout<<"\n\tGiven Vehicle is not present in Parking!!!\n";
        return;
     } 
  
     void SearchInFloorParking(int key) 
     {
        int CarIndex = key % CarCount, flag = 0;
        Floor *myNode;
        myNode = ParkingTable[CarIndex].head;
        if (!myNode)
		{
                cout<<"\n\tNo Vehicles unavailable in Parking Slots\n";
                return;
        }
        while (myNode != NULL) {
                if (myNode->key == key) {
                        cout<<"Floor No  :"<<myNode->key<<"\n";
                        cout<<"Car No     :"<<myNode->name<<"\n";
                        flag = 1;
                        break;
                }
                myNode = myNode->next;
        }
        if (!flag)
                cout<<"\n\tNo Vehicles unavailable in Parking Slots\n";
        return;
     }
  
    void Display() 
	{
        Floor *myNode;
        int i;
        for (i = 0; i < CarCount; i++) 
		{
                if (ParkingTable[i].count == 0)
                {
                	continue;
                }     
                myNode = ParkingTable[i].head;
                if (!myNode)
                {
                    continue;
                }
                
                cout<<"\nvehicles in floor "<<i<<" in ParkingTable:\n";
                cout<<"\n\nFloor Number       VehicleNumber\n";
                cout<<"--------------------------------\n";
                while (myNode != NULL)
				{
					    cout<<setw(6);
                        cout<<myNode->key;
                        cout<<setw(20);
                        cout<<myNode->name;
                        myNode = myNode->next;
                        cout<<"\n";
                }
        }
        return;
  }

  int main() 
  {
        int n, ch, floor;
  
  
        char car[10];
        cout<<"Enter the number of floors in Parking Bulding( 10 ):";
        cin>>n;
        CarCount = n;
        /* Create Parking Building with "n" Vehicles per floor */
        ParkingTable = (FloorParking  *)calloc(n, sizeof (FloorParking )); /* It will create a array or Blocks of Floor and returns address of pointer to this block*/
       
	    while (1)
		 {      system("cls");
                cout<<"\n1. Parking of Vehicle\n2. Unparking of Vehicle";
                cout<<"\n3. Searching of Vehicle\n4. Display of Parking Lots\n5. Exit\n";
                cout<<"Enter your choice:";
                cin>>ch;
                switch (ch) 
				{
                        case 1:
                                cout<<"\nEnter the floor number:";
                                cin>>floor;
                                cout<<"\nCar Number:";
                                cin>>car;
                                InsertToFloorParking(floor, car);
                                break;

                        case 2:
                                cout<<"Enter the Floor to perform unparking of vehicle:";
                                cin>>floor;
                                /* delete vehicle with "floor" from Parkingtable */
                                DeleteFromFloorParking(floor);
                                system("pause");
                                break;

                        case 3:
                                cout<<"Enter the floor to search:";
                                cin>>floor;
                                SearchInFloorParking(floor);
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

