#include "product.h"
#include <iostream>

void Product:: setname(std::string nm)
{
  m_name=nm;
}
void Product:: setid(int i)
{
  m_id=i;
}
void Product ::setqty(int qty)
{
  m_quantity=qty;
}
void Product:: setblock(char b)
{
  m_block=b;
}
void Product:: setshelf(int s)
{
  m_shelf=s;
}
void Product:: setPrice(double price)
{
  m_price_per_unit=price;
}
void Product:: setType(char type)
{
  m_type=type;
}

std::string Product:: getname()
{
  return m_name;
}
int Product::getid()
{
  return m_id;
}
int Product:: getqty()
{
  return m_quantity;
}
char Product:: getblock()
{
  return m_block;
}
int Product:: getshelf()
{
  return m_shelf;
}
char Product:: getType()
{
  return m_type;
}
double Product:: getPrice()
{
  return m_price_per_unit;
}
void Product :: locate()
{
  std::cout<<"Block "<<m_block<<"\n"<<"Shelf "<<m_shelf<<"\n";
}



