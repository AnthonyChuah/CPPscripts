#include <iostream>
using namespace std;
	
typedef int *IntPtrType;
		
int main()
{
  IntPtrType ptr_a, ptr_b, *ptr_c;
  // Created on Stack's Main() Stackframe three things:
  // 1. ptr_a address initialized to random address.
  // 2. ptr_b ditto.
  // 3. ptr_c address of a pointer to another address, also presently randomly initialized.
  
  ptr_a = new int;
  // Created on the HEAP a new slice of memory for an integer, and ptr_a now points to that address.
  
  *ptr_a = 3;
  // * is the "contents of" operator, and it's set the value of the heap data, to which ptr_a points, to 3.
  ptr_b = ptr_a;
  // ptr_b now made to point to the same address that ptr_a points to. That means both ptr_a and ptr_b point
  // at the heap integer with value 3.
  cout << *ptr_a << " " << *ptr_b << "\n";
  // Prints: 3 3
  
  ptr_b = new int;
  // Created on the HEAP a new slice of memory for an integer, and ptr_b now points to that address.
  *ptr_b = 9;
  // * is "contents of" operator, the heap data that ptr_b pointed to now has value 9.
  cout << *ptr_a << " " << *ptr_b << "\n";
  // Prints: 3 9
	
  *ptr_b = *ptr_a;
  // "contents of" ptr_b are now assigned the value that is in the "contents of" ptr_a, i.e. 3.
  cout << *ptr_a << " " << *ptr_b << "\n";
  // Prints: 3 3
	
  delete ptr_a;
  // Deletes from the heap the data (integer 3). ptr_a is pointing to the heap address but it no longer
  // has anything. Program no longer controls that heap address' contents. Completely unpredictable.
  ptr_a = ptr_b;
  // ptr_a now made to point to ptr_b's target.
  cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n";
  // Prints: 3 3
  
  ptr_c = &ptr_a;
  // & is the "address of" operator. ptr_c is a pointer to an integer pointer, so ptr_c now points to ptr_a.
  cout << *ptr_c << " " << **ptr_c << "\n";
  // Prints: ptr_a's VALUE (an address) and the number 3.
	
  delete ptr_a;
  // Delete from heap the data ptr_a was pointing to, i.e. 3. Note: this is the same thing ptr_b is pointing to.
  ptr_a = NULL;
  // Set ptr_a to the null pointer (so it does not dangle).
  return 0;
}
