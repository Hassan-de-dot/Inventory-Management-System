#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
  protected:
    std::string m_name{};
    int m_id{};
    int m_quantity{};
    char m_block{};
    int m_shelf{};
    double m_price_per_unit{};
    char m_type{};

    void setname(std::string nm);
    void setid(int i);
    void setqty(int qty);
    void setblock(char b);
    void setshelf(int s);
    void setPrice(double price);
    void setType(char type);
    
  public:
    Product(std::string name, char type, int id, int qty, char block, int shelf, double price)
    :
    m_name{name},
    m_type{type},
    m_id{id},
    m_quantity{qty},
    m_block{block},
    m_shelf{shelf},
    m_price_per_unit{price}
    {}
    // virtual ~Product()=default;
    virtual bool getSpecial()=0;
    virtual void setSpecial(bool attr )=0;
    virtual double totalPrice()=0;
    
    virtual ~Product()=default;

    std::string getname();
    int getid();
    int getqty();
    char getblock();
    int getshelf();
    
    double getPrice();
    char getType();
    void locate();

};
#endif
