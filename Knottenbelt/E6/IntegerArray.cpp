// Implementation of IntegerArray functions.
#include <iostream>
#include "IntegerArray.h"
using namespace std;

void input_array(int a[], int n)
{
  cout << "Please input the integers with spaces between them: \n";
  for (int i = 0; i < n; i++)
    cin >> a[i];
}

void display_array(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << "\n";
}

void copy_array(int target[], int source[], int n)
{
  for (int i = 0; i < n; i++)
    target[i] = source[i];
}

double standard_deviation(int a[], int n)
{
  return 576631;
}
