#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

// Declare method.
int digit_to_int(char c);

class Money
{
public:
  // Overloads binary operator +.
  friend Money operator +(const Money& amount1, const Money& amount2);
  // Binary operator - overloaded.
  friend Money operator -(const Money& amount1, const Money& amount2);
  // UNARY operator - overloaded.
  friend Money operator -(const Money& amount);
  // Overloads binary operator ==.
  friend bool operator ==(const Money& amount1, const Money& amount2);
  // Constructor with two arguments.
  Money(long dollars, int cents);
  // Constructors with one and no arguments respectively.
  Money(long dollars);
  Money();
  // Constant method get_value cannot modify object.
  double get_value() const;
  void input(istream& ins);
  // Constant method output cannot modify object.
  void output(ostream& outs) const;
private:
  long all_cents;
};

int main()
{
  Money cost(1, 50), tax(0, 15), total;
  total = cost + tax;

  cout << "cost = ";
  cost.output(cout);
  cout << endl;
  cout << "tax = ";
  tax.output(cout);
  cout << endl;
  cout << "total bill = ";
  total.output(cout);
  cout << endl;
  if (cost == tax)
    cout << "Wtf dude.\n";
  else
    cout << "Things seem normal.\n";
  return 0;
}

// Header and definition of operator overloading.
Money operator +(const Money& amount1, const Money& amount2)
{
  Money temp;
  temp.all_cents = amount1.all_cents + amount2.all_cents;
  return temp;
}

// Binary operator for - sign.
Money operator -(const Money& amount1, const Money& amount2)
{
  Money temp;
  temp.all_cents = amount1.all_cents - amount2.all_cents;
  return temp;
}

// UNARY operator for - sign.
Money operator -(const Money& amount)
{
  Money temp;
  temp.all_cents = -amount.all_cents;
  return temp;
}

// Operator overloading.
bool operator ==(const Money& amount1, const Money& amount2)
{
  return (amount1.all_cents == amount2.all_cents);
}

// Constructors.
Money::Money(long dollars, int cents)
{
  if (dollars * cents < 0)
    {
      cout << "Illegal values, gtfo.\n";
      exit(1);
    }
  all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
}

Money::Money() : all_cents(0)
{
}

double Money::get_value() const
{
  return (all_cents * 0.01);
}

void Money::input(istream& ins)
{
  char one_char, decimal_point, digit1, digit2;
  long dollars;
  int cents;
  bool negative;
  ins >> one_char;
  if (one_char == '-')
    {
      negative = true;
      ins >> one_char;
    }
  else
    negative = false;
  ins >> dollars >> decimal_point >> digit1 >> digit2;
  if (one_char != '$' || decimal_point != '.'
      || !isdigit(digit1) || !isdigit(digit2))
    {
      cout << "Wtf dude, illegal money.\n";
      exit(1);
    }
  cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
  all_cents = dollars * 100 + cents;
  if (negative)
    all_cents = -all_cents;
}

void Money::output(ostream& outs) const
{
  long positive_cents, dollars, cents;
  positive_cents = labs(all_cents);
  dollars = positive_cents / 100;
  cents = positive_cents % 100;
  if (all_cents < 0)
    outs << "-$" << dollars << '.';
  else
    outs << "$" << dollars << '.';
  if (cents < 10)
    outs << '0';
  outs << cents;
}

int digit_to_int(char c)
{
  return (static_cast<int>(c) - static_cast<int>('0'));
}
