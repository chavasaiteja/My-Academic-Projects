//Program to copy contents of file to another file.
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main()
{
     ifstream fin;
     fin.open("out.txt");
     ofstream fout;
     fout.open("sample.txt");
     char ch;
     while(!fin.eof())
     {
          fin.get(ch);
          fout<<ch;
     }
     fin.close();
     return 0;
}
