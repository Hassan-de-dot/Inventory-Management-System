#include "inventory.h"
#include "globals.h"
#include <iostream>
#include <string_view>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // std::sort

bool Inventory:: isPresent(int id)
{
  for(auto& product: inventory)
    if (product->getid()==id)
      return true;
  return false;
}
bool Inventory:: isPresent(const std::string& name)
{
  for(auto& product: inventory)
    if (product->getname()==name)
      return true;
  return false;
}
void Inventory:: sortInventory()
{
  std::sort(inventory.begin(), inventory.end(),
  [](const std::unique_ptr<Product>& a, const std::unique_ptr<Product>& b) {
      return a->getid() < b->getid();
  });
}
void Inventory::removeProduct(int id)
{
  size_t prev_size{inventory.size()};
  const std::string& name{getNameById(id)};
  auto it = std::remove_if(inventory.begin(), inventory.end(),
        [id](const std::unique_ptr<Product>& product) 
        {   
            return product->getid() == id;
        });

    // Erase the removed elements from the container.
    inventory.erase(it, inventory.end());
    if (prev_size>inventory.size())
      std::cout<<name<<" of id: "<<id<<" removed!\n";
    else
      std::cout<<"Object not found!\n";
  saveToFile(fileName);
  
}
void Inventory::removeProduct(const std::string& name)
{
  size_t prev_size{inventory.size()};
  auto it = std::remove_if(inventory.begin(), inventory.end(),
        [name](const std::unique_ptr<Product>& product) 
        {
          return product->getname() == name;
        });
    // Erase the removed elements from the container.
    inventory.erase(it, inventory.end());
  if (prev_size>inventory.size())
      std::cout<<name<<" removed!\n";
  else
      std::cout<<"Object not found!\n";
  saveToFile(fileName);
}
void Inventory:: removeDuplicates()
{
auto last = std::unique(inventory.begin(), inventory.end(),
        [](const std::unique_ptr<Product>& a, const std::unique_ptr<Product>& b) {
            return a->getname() == b->getname();
        });

    // Erase the duplicates
    inventory.erase(last, inventory.end());
}
void Inventory::loadFromFile(const std::string_view& filename)
{
  char type{};
  int id{};
  std::string name{};
  char block{};
  int shelf{};
  int quantity{};
  double price{};
  bool special{};

  std::ifstream infile{std::string(filename)};
  // If we couldn't open the output file stream for reading
  if (!infile)
  {
    // Print an error and exit
    std::cerr << "Uh oh,"<<filename<<" could not be opened for reading!\n";
  }
  while (infile >> type >> id >> name >> block >> shelf >> quantity >> price >> special) {
  if(type == 's') {
    inventory.push_back(std::make_unique<Solidproduct>(name, type, id, quantity, block, shelf, price, special));
  } else if(type == 'l') { 
    inventory.push_back(std::make_unique<Liquidproduct>(name, type, id, quantity, block, shelf, price, special));
  }
  }

  if (infile.fail() && !infile.eof()) {
    std::cerr << "An error occurred while reading from " << filename << "\n";
  }
  sortInventory();
  removeDuplicates();
  
}

void Inventory::saveToFile(const std::string_view& filename)
{
  std::ofstream outfile{std::string(filename)};
  if (!outfile)
  {
    // Print an error and exit
    std::cerr << "Uh oh, "<<filename<<" could not be opened for writing!\n";
  }
  for(int i{0};i<static_cast<int>(inventory.size());++i)
  {
    outfile<<inventory[i]->getType()<<" ";
    outfile<<inventory[i]->getid()<<" ";
    outfile<<inventory[i]->getname()<<" ";
    outfile<<inventory[i]->getblock()<<" ";
    outfile<<inventory[i]->getshelf()<<" ";
    outfile<<inventory[i]->getqty()<<" ";
    outfile<<inventory[i]->getPrice()<<" ";
    outfile<<inventory[i]->getSpecial()<<"\n";
  }
}


const int Inventory::getNewId()
{
  auto& last_product{inventory.back()};
  int last_id{last_product->getid()};
  return ++last_id;
}

bool Inventory::checkIfPresent(int id) {
    for (const auto& product: inventory) {
        if (product->getid() == id)
            return true;
    }
    return false;
}

bool Inventory::checkIfPresent(const std::string& name) {
    for (const auto& product: inventory) {
        if (product->getname() == name)
            return true;
    }
    return false;
}

void Inventory::addProduct(char type,std::string name,int quantity,char block,int shelf,double price,bool special)
{
  if (checkIfPresent(name))
    std::cout<<"Product Already Present"<<"\n";
  else
  {
    int id = getNewId();
    if(type == 's') {
      inventory.push_back(std::make_unique<Solidproduct>(name, type, id, quantity, block, shelf, price, special));
  } else if(type == 'l') { 
      inventory.push_back(std::make_unique<Liquidproduct>(name, type, id, quantity, block, shelf, price, special));
  }
    std::cout<<name<<" added!\n";
  }
  saveToFile(fileName);
}
const std::string Inventory::getNameById(int id)
{
  for(auto& product: inventory)
    if (product->getid()==id)
      return product->getname();
  return "???";
}
int Inventory:: getProductCount(int id)
{
  for(const auto& product: inventory)
  {
    if (product->getid()==id)
    {
      return product->getqty();
    }
  }
  std::cout<<"Product Not found !\n";
  return 0;
}

int Inventory:: getProductCount(const std::string& name)
{
  for(const auto& product: inventory)
  {
    if (product->getname()==name)
    {
      return product->getqty();
    }
  }
  std::cout<<"Product Not found !\n";
  return 0;
}
int  Inventory:: getUnitCount()
{
  return inventory.size();
}

double Inventory:: getInventoryValue()
{
  double inventory_total{0};
  for (const auto& product: inventory)
  {
    inventory_total+=product->totalPrice();
  }
  return inventory_total;
}
int Inventory::getSize()
{
  return inventory.size();
}
void Inventory::displayInventory()
{
  std::cout<<"ID"<<" ";
  std::cout<<"NAME"<<" ";
  std::cout<<"BLOCK"<<" ";
  std::cout<<"SHELF"<<" ";
  std::cout<<"QUANTITY"<<" ";
  std::cout<<"PRICE"<<" ";
  std::cout<<"Special(Flamamble/Fragile)"<<"\n";
  for (const auto& product: inventory)
  {
    std::cout<<product->getid()<<" ";
    std::cout<<product->getname()<<" ";
    std::cout<<product->getblock()<<" ";
    std::cout<<product->getshelf()<<" ";
    std::cout<<product->getqty()<<" ";
    std::cout<<product->getPrice()<<" ";
    std::cout<<product->getSpecial()<<"\n";
  }
}



