// Driver file for testing statistics.h and statistics.cpp.
#include <iostream>
#include "statistics.h"
using namespace std;

int main()
{
  int sample_size;
  cout << "This program tests the functions in the 'statistics.h' header file.\n\n"
       << "How many numbers do you wish to test? (Enter 0 to end the program): ";
  cin >> sample_size;
  if (sample_size == 0)
    {
      cout << "Program ended as requested.\n";
      exit(1);
    }
  else if (sample_size >= 100)
    {
      cout << "I think you'll find it too tedious to enter so many numbers. Get out.\n";
      exit(1);
    }
  else
    {
      double arr[100]; // Initialized fixed array.
    }
}
