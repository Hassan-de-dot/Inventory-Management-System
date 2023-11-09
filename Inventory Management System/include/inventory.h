#ifndef INVENTORY_H
#define INVENTORY_H

#include "liquid_product.h"
#include "solid_product.h"
#include "product.h"
// #include "globals.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string_view>

class Inventory
{
  private:
    std::vector<std::unique_ptr<Product>> inventory;
    void sortInventory();
    bool checkIfPresent(const std::string& name);
    bool checkIfPresent(int id);
  public:
    Inventory()
    {std::cout<<"Created!! \n";}
    void removeDuplicates();
    void loadFromFile(const std::string_view& filename);
    void saveToFile(const std::string_view& filename);
    int getSize();
    void displayInventory();
    void removeProduct(int id);
    void removeProduct(const std::string& name);
    void addProduct(char type,std::string name,int quantity,char block,int shelf,double price,bool special);
    const int getNewId();
    bool isPresent(int id);
    bool isPresent(const std::string& name);
    int getProductCount(int id);
    int getProductCount(const std::string& name);
    int getUnitCount();
    const std::string getNameById(int id);
    double getInventoryValue();
    void clearInventory();

};
#endif
