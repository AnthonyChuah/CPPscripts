#include <iostream>
using namespace std;

typedef int* IntPointer;

void sneaky(IntPointer temp);

int main()
{
  IntPointer p;
  p = new int;
  *p = 77;
  cout << "Before the call to function, p has value: "
       << *p << endl;
  cout << "Just for completeness sake I output p pointer value "
       << p << endl;
  sneaky(p);
  cout << "After call to function SNEAKY, p has value: "
       << *p << endl;
  cout << "Just for completeness sake I output p pointer value "
       << p << endl;
  return 0;
}

void sneaky(IntPointer temp)
{
  *temp = 99;
  cout << "Inside function call *temp is equal to "
       << *temp << endl;
}
