#include <iostream>
#include <string>
using namespace std;

class NegNumber
{
public:
  // Default Constructor
  NegNumber();
  // Constructor
  NegNumber(string goto_catchblock);
  string get_message();
private:
  string message;
};

class DivideByZero
{};

int main()
{
  int wizards, barbarians;
  double portion;
  try
    {
      cout << "Enter number of Wizards:\n";
      cin >> wizards;
      if (wizards < 0)
	throw NegNumber("Wizards");
      cout << "How many Barbarians do you have?\n";
      cin >> barbarians;
      if (barbarians < 0)
	throw NegNumber("Barbarians");
      if (barbarians != 0)
	portion = wizards/static_cast<double>(barbarians);
      else
	throw DivideByZero();
      cout << "Each Barbarian must fight " << portion << " Wizards.\n";
    }
  catch(NegNumber e)
    {
      cout << "Cannot have a negative number of "
	   << e.get_message() << endl;
    }
  catch(DivideByZero)
    {
      cout << "You cannot have zero Barbarians!\n";
    }
  cout << "End of program.\n";
  return 0;
}

NegNumber::NegNumber()
{}

NegNumber::NegNumber(string goto_catchblock)
  : message(goto_catchblock)
{}

string NegNumber::get_message()
{
  return message;
}
