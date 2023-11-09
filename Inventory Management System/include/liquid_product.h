#ifndef LIQUIDPRODUCT_H
#define LIQUIDPRODUCT_H

#include "product.h"
#include <iostream>

class Liquidproduct : public Product
{
  private:
    bool m_flamable{} ;

  public:
    Liquidproduct(std::string name,char type, int id, int qty, char block, int shelf, double price,  bool flamable)
    : 
    Product(name,type,id,qty,block,shelf,price), 
    m_flamable{flamable}
    {
      // std::cout<<m_name<<" is a liquid of id "<<m_id<<" price per unit "<<m_price_per_unit<<"\n";
    }

    bool getSpecial() override;
    void setSpecial(bool flm) override;
    double totalPrice();
    void isFlammable();

    virtual ~Liquidproduct() override = default;
} ;
 #endif// LIQUIDPRODUCT1_H
