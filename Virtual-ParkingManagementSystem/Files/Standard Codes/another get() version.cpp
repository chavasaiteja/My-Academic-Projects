// another get() version
#include <iostream>
using namespace std;
 
const int SIZE = 100;
 
main()
{
char bufferOne[SIZE], bufferTwo[SIZE];
 
cout <<"Enter a line of text:"<<endl;
cin>>bufferOne;
// store the string in array bufferOne
// just the first word in the array string, then the
// first whitespace encountered
cout<<"\nThe line of text read by cin>> was:"<<endl;
cout<<bufferOne<<endl;
cin.get(bufferTwo, SIZE);
// the rest of the string
cout<<"The line of text read by cin.get(bufferTwo,SIZE) was:"<<endl;
cout<<bufferTwo<<endl;
}
 
