// Demonstrates use of templates, applied to a sorting function.
// Function works on arrays of integers, doubles, characters.

#include <iostream>
using namespace std;

template<class T>
void swap_values(T& var1, T& var2)
{
  T temp;
  temp = var1;
  var1 = var2;
  var2 = temp;
}

template<class BaseType>
int index_of_smallest(const BaseType a[], int start_index, int number_used)
{
  BaseType min = a[start_index];
  int index_of_min = start_index;
  for (int index = start_index + 1; index < number_used; index++)
    if (a[index] < min)
      {
	// Set min to the new smaller element.
	min = a[index];
	index_of_min = index;
      }
  return index_of_min;
}

template<class BaseType>
void sort(BaseType a[], int number_used)
{
  int index_of_next_smallest;
  for (int index = 0; index < number_used - 1; index++)
    {
      // Place correct value in a[index]:
      index_of_next_smallest = index_of_smallest(a, index, number_used);
      swap_values(a[index], a[index_of_next_smallest]);
    }
}

int main()
{
  int i;
  
  // Test template sort on integer array.
  int a[10] = {9,8,7,6,5,1,2,3,0,4};
  cout << "Unsorted integers:\n";
  for (i = 0; i < 10; i++)
    cout << a[i] << ", ";
  cout << '\n';
  sort(a, 10);
  cout << "In sorted order the integers are:\n";
  for (i = 0; i < 10; i++)
    cout << a[i] << ", ";
  cout << '\n';
  
  // Test template sort on double array.
  double b[5] = {5.5, 4.4, 1.1, 3.3, 2.2};
  cout << "Unsorted doubles:\n";
  for (i = 0; i < 5; i++)
    cout << b[i] << ", ";
  cout << '\n';
  sort(b, 5);
  cout << "In sorted order the doubles are:\n";
  for (i = 0; i < 5; i++)
    cout << b[i] << ", ";
  cout << '\n';
  
  // Test template sort on character array.
  char c[7] = {'G','E','N','E','R','I','C'};
  cout << "Unsorted characters:\n";
  for (i = 0; i < 7; i++)
    cout << c[i] << ", ";
  cout << '\n';
  sort(c, 7);
  cout << "In sorted order the characters are:\n";
  for (i = 0; i < 7; i++)
    cout << c[i] << ", ";
  cout << '\n';

  return 0;
}
