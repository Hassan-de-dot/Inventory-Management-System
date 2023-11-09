#include "liquid_product.h"
#include<iostream>
#include "product.h"



bool Liquidproduct::getSpecial()
{
  return m_flamable;
}

void Liquidproduct:: setSpecial(bool flm)
{
m_flamable=flm;
}

double Liquidproduct::totalPrice()
{
return m_quantity*m_price_per_unit;
}
void Liquidproduct::isFlammable()
{
  if(m_flamable)
    std::cout<<"Is Flammable"<<std::endl;
  else 
    std::cout<<"Not Flammable"<<std::endl;
}
