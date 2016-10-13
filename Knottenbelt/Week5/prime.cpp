/*
Question 1

Write a logical (i.e. Boolean) valued function which takes a single integer parameter, and returns "True" if and only if the integer is a prime number between 1 and 1000 (note that 1 is not usually counted as a prime number). Test your function by calling it from an appropriate "driver" program with different inputs.
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool isprime(int value);
// Takes an integer input and checks if it is a prime number between 1 and 1000.
// Returns true if it is a prime number within range, false otherwise.

bool isprime(int value)
{
  if (value > 1000)
    return false;
  if (value <= 1)
    return false;
  for (int i = 2; i < 32; i++)
    {
      if (value % i == 0 && value != i)
	return false;
    }
  return true;
}

int main()
{
  // Check from 1 to 1000 and say if they are prime or not.
  for (int j = 1; j <= 1000; j++)
    {
      cout << setw(5) << j << ": ";
      if (isprime(j))
	cout << "Prime";
      else
	cout << "Compound";
      cout << "\n";
    }
  return 0;
}
