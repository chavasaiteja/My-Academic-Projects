// using read(), write() and gcount() member functions
#include <iostream>
using namespace std;
 
const int SIZE = 100;
 
main()
{
char buffer[SIZE];
 
cout<<"Enter a line of text:"<<endl;
cin.read(buffer,45);
cout<<"The line of text entered was: "<<endl;
cout.write(buffer, cin.gcount());
// the gcount() member function returns
// the number of unformatted characters last extracted
cout<<endl;
}
