// Demonstrate class constructors.
#include <iostream>
#include <cstdlib>
using namespace std;
class BankAccount
{
public:
  BankAccount(int dollars, int cents, double rate);
  // Initialize account balance to $dollars.cents,
  // and initialize interest rate to rate percent.
  BankAccount(int dollars, double rate);
  // Initialize account balance to $dollars.00,
  // and initialize interest rate to rate percent.
  BankAccount();
  // Initialize balance and rate to 0.
  void set(int dollars, int cents, double rate);
  void set(int dollars, double rate);
  void update();
  double get_balance();
  double get_rate();
  void output(ostream& outs);
private:
  double balance;
  double interest_rate;
  double fraction(double percent);
};

int main()
{
  BankAccount account1(100, 2.3), account2;
  cout << "account1 initialized as follows:\n";
  account1.output(cout);
  cout << "account2 initialized as follows:\n";
  account2.output(cout);
  account1 = BankAccount(999, 99, 5.5);
  cout << "account1 reset to the following:\n";
  account1.output(cout);
  account1.update();
  cout << "account1 grew to:\n";
  account1.output(cout);
  return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
  if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
      cout << "Illegal values for money or rate.\n";
      exit(1);
    }
  balance = dollars + 0.01*cents;
  interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
  if ((dollars < 0) || (rate < 0))
    {
      cout << "Illegal values for money or rate.\n";
      exit(1);
    }
  balance = dollars;
  interest_rate = rate;
}

BankAccount::BankAccount() : balance(0), interest_rate(0.0)
{
  // Intentionally empty.
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
