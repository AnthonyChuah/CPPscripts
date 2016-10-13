// Driver for testing IntegerArray functions.
#include <iostream>
#include "IntegerArray.h"
using namespace std;

int main()
{
  int array[5];
  input_array(array, 5);
  display_array(array, 5);
  int smaller[4];
  copy_array(smaller, array, 4);
  display_array(smaller, 4);
  cout << standard_deviation(array, 5);
}
