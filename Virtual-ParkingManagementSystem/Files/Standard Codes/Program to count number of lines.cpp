//Program to count number of lines
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main()
{
     ifstream fin;
     fin.open("out.txt");
     char str[80]; int count=0;
     while(!fin.eof())
     {
          fin.getline(str,80);
          count++;
     }
     cout<<"Number of lines in file is "<<count;
     fin.close();
     getch();
     return 0;
}
