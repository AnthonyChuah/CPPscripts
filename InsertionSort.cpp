// Program sorts an array using Insertion Sort algorithm.
#include <iostream>
#include <fstream>
#include <cstdlib>

void swap_values(int& first, int& second);
// Call-by-reference swapping of values.
void read_array(int arr[], int& arraysize);
// Read file containing array of values after requesting user input the file name.
void isort(int arr[], int arraysize);
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

void swap_values(int& first, int& second)
{
  int temp = second;
  second = first;
  first = temp;
  return;
}

void read_array(int arr[], int& arraysize)
{
  std::ifstream fin;
  std::ofstream fout;
  char filename[80];
  int indexcounter = 0;
  std::cout << "Begin reading text file.\n";
  std::cout << "What is the name of the text file?\n";
  std::cin >> filename;
  fin.open(filename);
  if (fin.fail())
    {
      std::cout << "File reading failed.\n";
      std::exit(1);
    }
  while (!fin.eof())
    {
      fin >> arr[indexcounter];
      indexcounter++;
    }
  arraysize = indexcounter;
  std::cout << "This is the array that has been read.\n";
  for (int i = 0; i < indexcounter; i++)
    {
      std::cout << arr[i] << " ";
    }
  std::cout << std::endl;
  std::cout << "This is the array size.\n";
  std::cout << arraysize << "\n";
  return;
}

void isort(int arr[], int arraysize)
{
  // Start from second position and insert it into the sorted part.
  // In first iteration, sorted part is only size of 2.
  // Put it to the left of a[0] if it's lower than a[0] and
  // shift a[0] value to a[1].
  for (int i = 1; i < arraysize; i++)
    {
      for (int j = i; j > 0; j--)
	{
	  // In decreasing sequence: if a[j-1] < a[j] then swap.
	  if (arr[j-1] < arr[j])
	    swap_values(arr[j-1], arr[j]);
	  else
	    // Earlier swaps make it unnecessary to swap if a[j]
	    // was not < a[j+1] in later iterations of i.
	    break;
	}
    }
  return;
}
