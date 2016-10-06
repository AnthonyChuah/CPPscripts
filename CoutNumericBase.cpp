#include <iostream>
using namespace std;

// You can do cout << dec << VARIABLE to print in decimal.
// Likewise you can do oct, hex, bin in place of dec for other bases.
int main()
{
  int number;
  char character;
	
  for (number = 32 ; number <= 126 ; number = number + 1) {
	
    character = number;
    cout << "The character '" << character;
    cout << "' is represented as the number ";
    cout << dec << number << " decimal or "
	 <<hex<<number<< " hex.\n";
  }

  return 0;
}
