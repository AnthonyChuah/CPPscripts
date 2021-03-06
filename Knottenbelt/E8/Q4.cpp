#include <iostream>
using namespace std;

int binary_search(int value, int list[], int first, int last)
{
  int halfway = (first + last) / 2;
  if (list[halfway] == value)
    return halfway;
  else if (first >= last)
    return -1;
  if (list[halfway] > value)
    return binary_search(value, list, first, halfway-1);
  else
    return binary_search(value, list, halfway+1, last);
}

int main()
{
  int a[10] = {2, 3, 5, 8, 14, 16, 22, 22, 24, 30};
  int index = -1, target;
  cout << "The array is: ";
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << "\nWhat value do you want to find? ";
  cin >> target;
  cout << "Calling binary search recursive function...\n";
  index = binary_search(target, a, 0, 9);
  if (index == -1)
    cout << "Could not find your value in the array.\n";
  else
    cout << "The index of the value you want to find is: " << index << "\n";
  return 0;
}
