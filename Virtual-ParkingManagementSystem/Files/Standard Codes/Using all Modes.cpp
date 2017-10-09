#include<iostream>
#include<fstream>

using namespace std;

int main()
{
char rel[20];

ofstream fout;
fout.open("one.txt");

fout<<"First Line \n";
fout<<"Second Line \n";
fout<<"Third Line \n";
fout<<"Fourth Line \n";
fout<<"Fifth Line\n";

fout.close();

//Reading all values using while(fin)

ifstream fin("one.txt");

while(fin)
{
fin.getline(rel,20);
cout<<"\n "<<rel;
}

fin.close();

//Reading all values using eof() method

fin.open("one.txt");

while(1)
{
if(fin.eof()!=0)
{
break;
}
fin.getline(rel,20);
cout<<"\n "<<rel;
}

fin.close();

//fstream Class object + Mode

fstream file("one.txt",ios::in);

while(1)
{
if(file.eof()!=0)
{
break;
}
file.getline(rel,20);
cout<<"\n "<<rel;
}

file.close();

return 0;
}
