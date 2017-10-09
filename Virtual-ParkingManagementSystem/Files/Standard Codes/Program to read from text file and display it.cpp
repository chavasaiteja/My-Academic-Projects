#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
     ifstream fin;
     fin.open("out.txt");
     char ch;char str[300];
     while(!fin.eof())
     {
          fin.get(ch);
          cout<<ch;
     }
     fin>>str;
     cout<<str;
     fin.close();
     getch();
     return 0;
}
