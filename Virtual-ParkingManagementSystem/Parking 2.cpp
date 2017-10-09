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

class Parking()
{
	Node *Head=NULL,*NewNode,*Traversal,*Tail;
	
	public:
		void Method1();
		
}

void Parking::Method1()
{
	int i=0;
     printf("\nInsertion at First  of linked list - 1");
     printf("\nInsertion at the end of linked list - 2");
     printf("\nInsertion at the middle where you want - 3");
     printf("\nDeletion from the end of linked list - 4");
     printf("\nDeletion from the top of linked list -5");
     printf("\nDeletion of the data that you want - 6");
     printf("\nFor Backward Travrsal of the LinkList - 7");
     printf("\nExit - 8\n");
     while(1)
     {
           printf("\n\nEnter the choice of operation to perform on linked list : ");
           scanf("%d",&i);
           switch(i)
           {
                case 1:
                {
                 int value;
                 printf("\n\nEnter the value to be inserted : ");
                 scanf("%d",&value);
                 Insert_Begining(value);
                 Display();                
                 break; 
                }
                case 2:
                {  
                int value;
                printf("\n\nEnter value to be inserted : ");
                scanf("%d",&value);
                Insert_End(value);
                Display();
                break;
                }
                case 3:
                {
                int value,location;
                printf("\n\nLocation after which(data) you want to insert the data: ");
                scanf("%d",&location);
                printf("\n\nEnter the value to be inserted: ");
                scanf("%d",&value);
                Insert_Middle(value,location);
                Display();
                break;
                }
                case 4:
                {
                Delete_End();//****************************VVVV.IMP
                Display();
                break;
                }
                case 5:
                {
                Delete_Head();
                Display();
                break;
               	}
               	case 6:
               	{
               	int value;
                Display();
                printf("\n\nEnter the data that you want to delete from the list shown above: ");
                scanf("%d",&value);
                Delete_Middle(value);
                Display();
                break;
               	}
               	case 7:
                foo(Head);
                
               	case 8:
               	{
               	 exit(0);//********To Get OUT of infinite While Loop.	
               	}
               	
            }
    }
}
