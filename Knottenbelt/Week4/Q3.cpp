/*
Question 3

Write a program which counts and displays the number of characters (including blanks) in its own source code file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char character;
  ifstream ins;
  int counter = 0;
  ins.open("Q3.cpp");
  while (!ins.fail())
    {
      ins.get(character);
      counter++;
    }
  ins.close();
  cout << "The number of characters in this code file is: " << counter << endl;
}
