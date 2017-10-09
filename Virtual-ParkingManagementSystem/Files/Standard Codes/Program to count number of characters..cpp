#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main()
{
     ifstream fin;
     fin.open("out.txt");
    system("cls");
     char ch; int count=0;
     while(!fin.eof())
     {
          fin.get(ch);
          count++;
     }
     cout<<"Number of characters in file is "<<count;
     fin.close();
     getch();
     return 0;
}
