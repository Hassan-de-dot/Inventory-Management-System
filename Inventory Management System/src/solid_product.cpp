#include "solid_product.h"
#include<iostream>


bool Solidproduct:: getSpecial()
{
  return m_fragile;
}

void Solidproduct:: setSpecial(bool frg)
{
  m_fragile=frg;
}

double Solidproduct:: totalPrice()
{
  return m_quantity*m_price_per_unit;
}
void Solidproduct:: isFragile()
{
  if(m_fragile==true)
    std::cout<<"Is Fragile"<<std::endl;
  else 
    std::cout<<"Not Fragile"<<std::endl;
}


