// Implementation of base class Sale, sale.h
#include "sale.h"

namespace sellingbear
{
  Sale::Sale() : price(0)
  {}
  Sale::Sale(double the_price) : price(the_price)
  {}
  double Sale::bill() const
  {
    return price;
  }
  double Sale::savings(const Sale& other) const
  {
    return (bill() - other.bill());
  }
  bool operator <(const Sale& first, const Sale& second)
  {
    // Because of polymorphism, will correctly apply subclass method
    // bill() instead of superclass method if subclass method implemented.
    return (first.bill() < second.bill());
  }
} // End of namespace sellingbear.
