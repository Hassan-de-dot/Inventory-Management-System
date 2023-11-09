#ifndef SOLIDPRODUCT_H
#define SOLIDPRODUCT_H

#include "product.h"
#include <iostream>

class Solidproduct : public Product
{
  private:
    bool m_fragile;

  public:
    Solidproduct(std::string name, char type, int id, int qty, char block, int shelf, double price,  bool fragile)
    :
    Product(name,type,id,qty,block,shelf,price), 
    
    m_fragile{fragile}
    {
      // std::cout<<m_name<<" is a solid of id "<<m_id<<" price per unit "<<m_price_per_unit<<"\n";
    }

    bool getSpecial() override;
    void setSpecial(bool frg) override;
    double totalPrice();
    void isFragile();

    virtual ~Solidproduct() override = default;
};

#endif// SOLIDPRODUCT1_H
