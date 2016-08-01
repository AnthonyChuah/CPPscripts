// Program to demonstrate recursive function for binary search.
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;

void search(const int a[], int first, int last,
	    int key, bool& found, int& location);
// Precondition: a[first] through a[last] are sorted in increasing order.
// Postcondition: if key is not one of the values a[first] through a[last],
// then found == false; otherwise, a[location] == key and found == true.

int main()
{
  int a[ARRAY_SIZE];
  const int final_index = ARRAY_SIZE - 1;
  // Insert some code to fill the array and sort it.
  a[0] = 2050;
  a[1] = 2055;
  a[2] = 2060;
  a[3] = 2065;
  a[4] = 2070;
  a[5] = 2075;
  a[6] = 2080;
  a[7] = 2085;
  a[8] = 2090;
  a[9] = 2095;
  // End of code to fill the array.
  int key, location;
  bool found;
  cout << "Enter number to be located: ";
  cin >> key;
  search(a, 0, final_index, key, found, location);
  if (found)
    cout << key << " is in index location " << location << endl;
  else
    cout << key << " is not in the array." << endl;
  return 0;
}

void search(const int a[], int first, int last, int key,
	    bool& found, int& location)
{
  int mid;
  if (first > last)
    found = false;
  else
    {
      mid = (first + last)/2;
      if (key == a[mid])
	{
	  found = true;
	  location = mid;
	}
      else if (key < a[mid])
	{
	  search(a, first, mid-1, key, found, location);
	}
      else if (key > a[mid])
	{
	  search(a, mid+1, last, key, found, location);
	}
    }
}
