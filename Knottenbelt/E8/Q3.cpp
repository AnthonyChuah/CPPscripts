/*
Question 3

Given positive two integers m and n such that m<n, the greatest common divisor of m and n is the same as the
greatest common divisor of m and (n-m). Use this fact to write a recursive definition of the function
"greatest_common_divisor(...)", which takes two positive integer arguments and returns their greatest common
divisor. Test your function in a suitable main program.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int m, int n)
{
  if (m == n)
    return m;
  else if (m > n)
    {
      cout << "First arg cannot be greater than second arg.\n";
      exit(1);
    }
  if (n - m < m)
    return gcd(n - m, m);
  else
    return gcd(m, n - m);
}

int main()
{
  int first = 0, second = 0;
  cout << "Enter the first number: ";
  cin >> first;
  cout << "Enter the second number: ";
  cin >> second;
  cout << "The greatest common divisor of the two numbers is: " << gcd(first, second) << "\n";
  return 0;
}
