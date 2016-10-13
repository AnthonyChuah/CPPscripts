#include <iostream>
using namespace std;

void print_pyramid(int height);
// Prints a pyramid of specified height. Must be between 1 to 30 inclusive.

int main()
{
  int desired_height = 0;
  bool acceptable_input = false;
  cout << "This program prints a 'pyramid' shape of\n"
       << "a specified height on the screen.\n\n";
  while (!(acceptable_input))
    {
      cout << "How high would you like the pyramid? (1 to 30 inclusive): ";
      cin >> desired_height;
      if (desired_height >= 1 && desired_height <= 30)
	{
	  acceptable_input = true;
	}
      else
	{
	  acceptable_input = false;
	}
    }
  print_pyramid(desired_height);
  return 0;
}

void print_pyramid(int height)
{
  int preceding_spaces = 0;
  int rownum = 0, num_stars = 0;
  for (int i = 0; i < height; i++)
    {
      preceding_spaces = height - 1 - i;
      // Print the preceding spaces.
      for (int j = 0; j < preceding_spaces; j++)
	cout << " ";
      // Print the stars.
      rownum = i + 1;
      num_stars = rownum * 2;
      for (int k = 0; k < num_stars; k++)
	cout << "*";
      // Print a newline.
      cout << "\n";
    }
}
