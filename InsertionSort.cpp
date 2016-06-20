// Program sorts an array using Insertion Sort algorithm.
#include <iostream>
#include <fstream>

void swap_values(int& first, int& second);
// Call-by-reference swapping of values.
void read_array(int& arr[], int& arraysize);
// Read file containing array of values after requesting user input the file name.
void isort(int& arr[], int arraysize);
// Performs insertion sort on the array.


int main()
{
  int arr[256];
  int asize;
  // Call-by-reference function will read values into declared array arr.
  std::cout << "Reading the array from the file.\n";
  read_array(arr, asize);
  // Call-by-reference function will sort the elements within array arr.
  isort(arr, asize);
  // Outputs the array arr.
  std::cout << "The sorted array is:\n";
  for (int i = 0; i < asize; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
  return 0;
}
