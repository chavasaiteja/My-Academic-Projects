#include<fstream>
#include<iostream>
using namespace std;
int main()
{
     ofstream fout;
     fout.open("out.txt");
     char str[300]="Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
     fout<<str;
     cout<<"Data given in program is taken into file..";
     fout.close();
     return 0;
}
