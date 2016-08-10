// Demonstrates use of virtual function bill().
#include <iostream>
#include "sale.h"
#include "discountsale.h"
using namespace std;
using namespace sellingbear;

int main()
{
  Sale simple(10.00);
  DiscountSale discount(11.00,10); // 11 gross price with 10% discount.
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  // The overloaded less-than < operator uses the virtual function bill()
  // which it knows from the superclass (Sale) argument it accepts.
  // Therefore it waits until run-time to determine which version of bill()
  // to take, because bill() in superclass is virtual.
  // If this were not the case, it would mistakenly bind to the superclass bill()
  // Even if you have used a subclass object in the operator argument when you
  // called the operator.
  if (discount < simple)
    {
      cout << "Discounted item is cheaper.\n";
      cout << "Savings is $" << simple.savings(discount) << endl;
    }
  else
    cout << "Discounted item is not cheaper.\n";
  return 0;
}
