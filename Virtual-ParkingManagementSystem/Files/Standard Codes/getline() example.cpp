
// getline() example
#include <iostream>
using namespace std;
 
const int SIZE = 100;
 
 main()
{
char buffer[SIZE];
 
cout<<"Read by cin.getline(buffer, SIZE)\n"
    <<"--------------------------------\n"<<"Enter a line of text:"<<endl;
cin.getline(buffer, SIZE);
cout<<"The line of text entered is: "<<endl;
cout<<buffer<<endl;
}
 
