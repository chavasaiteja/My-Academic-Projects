#include<iostream>
using namespace std;
#include<conio.h>
#include<stdlib.h>
#include<strings.h>

struct node
{
    char data[10];
    //int floor;
    struct node *next;
}*head,*var,*trav;

void insert_at_begning(char* value)
{
     var=(struct node *)malloc(sizeof (struct node));
     strcpy(var->data,value);
     if(head==NULL)
     {
         head=var;
         head->next=NULL;
     }
     else
     {
         var->next=head;
         head=var;
     }
}

void insert_at_end(char* value)
{
      struct node *temp; 
      temp=head;
      var=(struct node *)malloc(sizeof (struct node));
      strcpy(var->data,value);
      if(head==NULL)
      {
          head=var;
          head->next=NULL;
      }
      else
      {
          while(temp->next!=NULL)
          {     
               temp=temp->next;
          }
          var->next=NULL;
          temp->next=var;
      }
}

void insert_at_middle(char* value, char* loc)
{
     struct node *var2,*temp;
     var=(struct node *)malloc(sizeof (struct node));
     strcpy(var->data,value);
     temp=head;

     if(head==NULL)
     {
          head=var;
          head->next=NULL;
     }
     else
     {
          while(strcmp(temp->data,loc)!= 0)
          {
                temp=temp->next;
          }
          var2=temp->next;
          temp->next=var;
          var->next=var2;
     }
}

int delete_from_middle(char* value)
{
     struct node *temp,*var;
     temp=head;
     while(temp!=NULL)
     {
          if(strcmp(temp->data ,value)== 0)
          {
                if(temp==head)
                {
                     head=temp->next;
                     free(temp);
                     return 0;
                }
                else
                {
                     var->next=temp->next;
                     free(temp);
                     return 0;
                }
          }
          else
          {
               var=temp;
               temp=temp->next;
          }
     }
cout<<"data deleted from list is "<<value;
}

int delete_from_end()
{
     struct node *temp;
     temp=head;
     while(temp->next != NULL)
     {
          var=temp;
          temp=temp->next;
     }
     if(temp ==head)
     {
          head=temp->next; 
          free(temp);
          return 0;
     }
     cout<<"data deleted from list is "<<temp->data;
     var->next=NULL;
     free(temp);
     return 0;
}

void display()
{
     trav=head;
     if(trav==NULL)
     {
          cout<<"\nList is Empty";
     }
     else
     {
          cout<<"\nElements in the List: ";
          while(trav!=NULL)
          {
               cout<<" -> "<<trav->data;
               trav=trav->next;
          }
      cout<<"\n";
      }
}

int main()
{
     int i=0;
     head=NULL;
     cout<<"insertion at begning of linked list - 1";
     cout<<"\ninsertion at the end of linked list - 2";
     cout<<"\ninsertion at the middle where you want - 3";
     cout<<"\ndeletion from the end of linked list - 4";
     cout<<"\ndeletion of the data that you want - 5";
     cout<<"\nexit - 6\n";
     while(1)
     {
           cout<<"\nenter the choice of operation to perform on linked list";
           cin>>i;
           switch(i)
           {
                case 1:
                {
                 char value[10];
                 cout<<"\nenter the value to be inserted";
                 cin>>value;
                 insert_at_begning(value);
                 display();                
                 break; 
                }
                case 2:
                {  
                char value[10];
                cout<<"\nenter value to be inserted";
                cin>>value;
                insert_at_end(value);
                display();
                break;
                }
                case 3:
                {
                char value[10],loc[10];
                cout<<"\nafter which data you want to insert the data";
                cin>>loc;
                cout<<"\nenter the value to be inserted";
                cin>>value;
                insert_at_middle(value,loc);
                display();
                break;
                }
                case 4:
                {
                delete_from_end();
                display();
                break;
                }
                case 5:
                {
                char value[10];
                display();
                cout<<"\nenter the data that you want to delete from the list shown above";
                cin>>value;
                delete_from_middle(value);
                display();
                break;
                }
                case 6:
                {
                exit(0);
                }
           }
      }
getch();
}
