// Header interface for subclass DiscountSale of Sale.
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

namespace sellingbear
{
  // This declares DiscountSale as subclass of Sale.
  class DiscountSale : public Sale
  {
  public:
    DiscountSale();
    DiscountSale(double the_price, double the_discount);
    // Discount is expressed as percent of price.
    virtual double bill() const;
  protected:
    double discount;
  };
} // End of namespace sellingbear

#endif
