#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main()
{
     ifstream fin;
     fin.open("out.txt");
     char word[30]; int count=0;
     while(!fin.eof())
     {
          fin>>word;
          count++;
         cout<<fin.tellg()<<"\n";
          
     }
     cout<<"Number of words in file is "<<count;
     fin.close();
     getch();
     return 0;
}
