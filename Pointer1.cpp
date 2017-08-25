// Program to demonstrate pointers and dynamic variables.
#include <iostream>
using namespace std;

int main()
{
  // Declare two pointers p1 and p2.
  int *p1, *p2;
  p1 = new int;
  *p1 = 42;
  p2 = p1;
  cout << "*p1 is equal to " << *p1 << endl;
  cout << "*p2 is equal to " << *p2 << endl;
  *p2 = 53;
  cout << "*p1 is equal to " << *p1 << endl;
  cout << "*p2 is equal to " << *p2 << endl;
  p1 = new int;
  *p1 = 88;
  cout << "*p1 is equal to " << *p1 << endl;
  cout << "*p2 is equal to " << *p2 << endl;
  cout << "Hope you got the POINT of this example!\n";
  return 0;
}
