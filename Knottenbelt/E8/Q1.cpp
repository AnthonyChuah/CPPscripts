#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacci(int position);
// Recursive function calculates the value of the number in a given position in the Fibonacci sequence.

int main()
{
  cout << fibonacci(1) << ", "
       << fibonacci(2) << ", "
       << fibonacci(3) << ", "
       << fibonacci(4) << ", "
       << fibonacci(5) << ", "
       << fibonacci(6) << ", "
       << fibonacci(7) << "\n";
  return 0;
}

int fibonacci(int position)
{
  if (position <= 0)
    {
      cout << "Input integer cannot be 0 or negative.\n";
      exit(1);
    }
  if (position == 1 || position == 2)
    return 1;
  else
    {
      return (fibonacci(position-1) + fibonacci(position-2));
    }
}
