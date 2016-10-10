/*
Question 1

Write a program which outputs its own C++ source file to the screen.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char character;
  ifstream ins;
  ins.open("Q1.cpp");
  while (!ins.fail())
    {
      ins.get(character);
      cout << character;
    }
  ins.close();
}
