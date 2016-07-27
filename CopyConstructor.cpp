// Definition for class StringVar.
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

class StringVar
{
public:
  StringVar(int size);
  // Constructor makes object that can accept string values up to size.
  StringVar();
  // Constructs object to accept string of length 100 or less.
  StringVar(const char a[]);
  // Constructs object to make a StringVar with same characters as a[].
  StringVar(const StringVar& string_object);
  // Copies constructor from another StringVar object.
  ~StringVar();
  // Destructor returns dynamic memory to the heap.
  int length() const;
  // Returns length of the string value. Not FRIEND function because
  // it does not need access to private attributes.
  void input_line(istream& ins);
  // Enters characters from the input stream (file or console).
  friend ostream& operator <<(ostream& outs, const StringVar& the_string);
  // Overloads the << operator so it can output values of type StringVar.
private:
  char *value;
  // Pointer to the dynamic array that holds the string value.
  int max_length;
  // Declared max length of any string value.
};

StringVar::StringVar(int size) : max_length(size)
{
  value = new char[max_length + 1];
  value[0] = '\0';
  // We put it in position 0 because the string is empty for now.
  // Since it's a C string we need '\0' to be in there somewhere.
}

StringVar::StringVar() : max_length(100)
{
  value = new char[max_length + 1];
  value[0] = '\0';
  // Again, same deal.
}

StringVar::StringVar(const char a[]) : max_length(strlen(a))
{
  value = new char[max_length + 1];
  strcpy(value, a);
}

// Uses cstring, cstdlib, and also cstddef.
// This constructor copies another object of StringVar type.
StringVar::StringVar(const StringVar& string_object)
  : max_length(string_object.length())
{
  value = new char[max_length + 1];
  strcpy(value, string_object.value);
}

StringVar::~StringVar()
{
  delete [] value;
}

int StringVar::length() const
{
  return strlen(value);
}

void StringVar::input_line(istream& ins)
{
  ins.getline(value, max_length + 1);
}

ostream& operator <<(ostream& outs, const StringVar& the_string)
{
  outs << the_string.value;
  return outs;
}

void conversation(int max_name_size);
// Converses with the user.

void conversation(int max_name_size)
{
  using namespace std;
  StringVar your_name(max_name_size), our_name("Borg");
  cout << "What is your name?\n";
  your_name.input_line(cin);
  cout << "We are " << our_name << endl;
  cout << "We will meet again " << your_name << endl;
}

int main()
{
  using namespace std;
  StringVar line(20), motto("Constructors can help.");
  cout << "Enter a string of length 20 or less:\n";
  line.input_line(cin);
  StringVar temp(line);
  return 0;
}
