// Script to show string_sort.
#include <iostream>
using namespace std;

void swap_values(int& a, int& b)
{
  if (&a != &b)
    {
      a ^= b;
      b ^= a;
      a ^= b;
    }
}

void selection_sort(int a[], int size)
{
  for (int i = 0; i < size; i++)
    {
      // Find minimum value to the right of current i index.
      int min_index = i;
      for (int j = i; j < size; j++)
	{
	  if (a[j] < a[min_index])
	    min_index = j;
	}
      swap_values(a[i], a[min_index]);
    }    
}

void copy_array(int target[], int source[], int n)
{
  for (int i = 0; i < n; i++)
    target[i] = source[i];
}

void string_sort(char str[], int n)
{
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = static_cast<int>(str[i]);
  int sorted[n];
  copy_array(sorted, arr, n);
  selection_sort(sorted, n);
  for (int i = 0; i < n; i++)
    str[i] = static_cast<char>(sorted[i]);
}

int main()
{
  char input_str[80] = "Rob Miller";
  string_sort(input_str, 10);
  cout << "The sorted string is: " << input_str;
  return 0;
}
