// end of file controls depend on system
// Ctrl-z followed by return key - IBM PC, Ctrl-d - UNIX and MAC
#include <iostream>
using namespace std;
 main()
{
char p;
 
cout <<"Using member functions get(), eof() and put()\n"
     <<"---------------------------------------------"<<endl;
cout<<"Before any input, cin.eof() is "<<cin.eof()<<endl;
cout<<"Enter a line of texts followed by end of file control: "<<endl;
 
while((p = cin.get()) !='EOF')
    cout.put(p);
cout<<"\nAfter some text input, cin.eof() is "<<cin.eof()<<endl;
}
