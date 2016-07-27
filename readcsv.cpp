// Script reads csv file.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
typedef string* StringPtr;

int main()
{
  int MAX_CHARS_PER_LINE = 1024;
  // Declare pointer to dynamic array rowdata because we do not know
  // at compilation time the number of rows in the csv file.
  vector<string> rowdata;
  string rowstring;
  ifstream finstream;
  int numrows = 0;
  cout << "Begin reading the csv file.\n";
  finstream.open("items.csv");
  if (finstream.fail())
    {
      cout << "Input file opening failed.\n";
      exit(1);
    }
  while(!finstream.eof())
    {
      cout << "Reading row number " << numrows << "!\n";
      getline(finstream,rowstring);
      rowdata.push_back(rowstring);
      numrows++;
      cout << "Reading line of data: " << rowstring << "\n";
    }
  finstream.close();
  cout << "Total number of rows: " << numrows << "\n";
  cout << "Finished reading the csv file.\n";
  // Now print out the data in the array.
  for (int i = 0; i < numrows; i++)
    {
      cout << "First row of rawdata: " << rowdata[i] << "\n";
    }
  return 0;
}
