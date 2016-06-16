// Asks for user to input a roman numeral and outputs the decimal value.
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int RomanToInt(const char romanarray[], int strlength);
// Function takes a char array and the length of the string and
// returns the integer value for the roman numerals.

int main()
{
  std::string roman;
  int strlength, answer;
  char romanarray[1024];
  
  cout << "What roman numeral would you like me to translate?\n";
  cin >> roman;
  cout << "You wanted to translate " << roman << ".\n";
  // Call function to turn roman numerals string into integer.
  strlength = roman.length();
  cout << "It has " << strlength << " characters.\n";
  
  strncpy(romanarray, roman.c_str(), sizeof(romanarray));
  romanarray[sizeof(romanarray) - 1] = 0;

  cout << "I copied the string over to a character array: ";
  for (int i = 0; i < strlength; i++)
    {
      cout << romanarray[i];
    }
  cout << endl;

  answer = RomanToInt(romanarray, strlength);
  cout << "I translated your roman numerals to: " << answer << endl;
  cout << "Type anything to exit." << endl;
  cin >> answer;
  return 0;
}

int RomanToInt(const char romanarray[], int strlength)
{
  std::map<char, int> romanmap;
  char romanchar, lastchar;
  int counter = 0, lastadd = 0, toadd = 0;

  romanmap['M'] = 1000;
  romanmap['D'] = 500;
  romanmap['C'] = 100;
  romanmap['L'] = 50;
  romanmap['X'] = 10;
  romanmap['V'] = 5;
  romanmap['I'] = 1;

  for (int i = 0; i < strlength; i++)
    {
      romanchar = romanarray[i];
      toadd = romanmap[romanchar];
      if (toadd > lastadd && lastadd != 0)
	{
	  // Undo the lastadd, because lastadd was meant as a decrement.
	  counter -= lastadd;
	  // Now decrement by lastadd and increment by toadd.
	  counter -= lastadd;
	  counter += toadd;
	  // Record this step as lastadd for the next iteration.
	  lastadd = toadd;
	}
      else
	{
	  counter += toadd;
	  lastadd = toadd;
	}
    }
  
  return(counter);
}
