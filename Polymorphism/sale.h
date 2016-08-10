// Header interface sale.h for class Sale
#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;

namespace sellingbear
{
  class Sale
  {
  public:
    Sale();
    Sale(double the_price);
    virtual double bill() const;
    double savings(const Sale& other) const;
  protected:
    // Protected means subclasses can access this but other classes cannot.
    double price;
  }

  bool operator <(const Sale& first, const Sale& second);
  // Compares two sales to see which has larger net price.
} // End of namespace sellingbear.

#endif
