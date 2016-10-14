#include <iostream>
#include <cstring>
using namespace std;

// If first is alphabetically smaller than second, return True.
bool compare_bigness_strings(char first[], char second[])
{
  char* j = second;
  for (char* i = first; true; i++)
    {
      if (static_cast<int>(*i) < static_cast<int>(*j))
	return true;
      else if (static_cast<int>(*i) > static_cast<int>(*j))
	return false;
      else if (*i == '\0')
	return false;
      else
	j++;
	continue;
    }
  return false;
}

int main()
{
  char first_in[80], second_in[80];
  cout << "Test bigness comparison string first: ";
  cin >> first_in;
  cout << "Test bigness comparison string second: ";
  cin >> second_in;
  bool result;
  result = compare_bigness_strings(first_in, second_in);
  if (result)
    cout << "The function returned TRUE, so first is alphabetically smaller.\n";
  else
    cout << "The function returned FALSE, so first is not alphabetically smaller.\n";
  return 0;
}
