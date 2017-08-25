// Program demonstrates class BankAccount.
#include <iostream>
#include <cstdlib>
using namespace std;

// Class for bank account.
class BankAccount
{
public:
  void set(int dollars, int cents, double rate);
  // Balance = $dollars.cents.
  // Interest rate in percent.
  void set(int dollars, double rate);
  // Overload set function in case balance = $dollars.
  void update();
  // Add one year of simple interest to account balance.
  double get_balance();
  // Return current account balance.
  double get_rate();
  // Return current account interest rate as percentage.
  void output(ostream& outs);
  // If the output stream is a file stream, it must be
  // connected to a file.
  // Postcondition: account balance and interest rate will
  // be written to the output stream.
private:
  double balance;
  double interest_rate;
  double fraction(double percent);
  // Converts percentage to fraction.
};

int main()
{
  BankAccount account1, account2;
  cout << "Start of Test:\n";
  account1.set(123, 99, 3.0);
  cout << "account1 statement:\n";
  account1.output(cout);
  account1.set(100, 5.0);
  cout << "account1 with new setup:\n";
  account1.output(cout);
  account1.update();
  cout << "account1 after update:\n";
  account1.output(cout);
  account2 = account1;
  cout << "account2:\n";
  account2.output(cout);
  return 0;
}

void BankAccount::set(int dollars, int cents, double rate)
{
  if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
      cout << "Illegal values for input to BankAccount.\n";
      exit(1);
    }
  balance = dollars + 0.01*cents;
  interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
  if ((dollars < 0) || (rate < 0))
    {
      cout << "Illegal values for input to BankAccount.\n";
      exit(1);
    }
  balance = dollars;
  interest_rate = rate;
}

void BankAccount::update()
{
  balance = balance + fraction(interest_rate)*balance;
}

double BankAccount::fraction(double percent_value)
{
  return (percent_value / 100.0);
}

double BankAccount::get_balance()
{
  return balance;
}

double BankAccount::get_rate()
{
  return interest_rate;
}

void BankAccount::output(ostream& outs)
{
  outs.setf(ios::fixed);
  outs.setf(ios::showpoint);
  outs.precision(2);
  outs << "Account balance $" << balance << endl;
  outs << "Interest rate " << interest_rate << "%" << endl;
}
