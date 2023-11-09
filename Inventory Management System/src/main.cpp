#include <iostream>
#include "inventory.h"
#include "utils.h"
#include "globals.h"
#include <fstream>
#include <string>
#include <sstream> 
#include <limits>


int main()
{
  
  int option{};
  Inventory i;
  i.loadFromFile(fileName);
  std::string input{};
  printOptions();
  while(true)
  {  
    option=getInput<int>("Select one of the above options.\n");
    switch (option) {
      case 0:
      break;
      case 1:
          i.displayInventory();
          break;
      case 2:
        input=getInput<std::string>("Enter a name or an ID: \n");
        if (isNumber(input)) 
        {
          i.removeProduct(convertToInt(input));
        }
        else
        {
          i.removeProduct(input);
        }
        break;
      case 3:
      {
        std::string name{};
        char block{};
        char type{};
        int shelf{};
        int quantity{};
        double price{};
        bool special{};

        std::cout << "Add a new product selected" << "\n";

        name=getInput<std::string>("Input product name:\n");
        type=getInput<char>("Input product type (s)olid or (l)iquid:\n");
        if (type=='s')
        {
          special=getInput<bool>("Is it fragile?\n");
        }
        else if(type=='l')
        {
          special=getInput<bool>("Is it flamable?\n");
        }
        else
        {
          std::cout<<"Adding failed, try again!\n";
          std::cout<<"Accepted types: s or l \n";
          break;
        }
        quantity=getInput<int>("Input the product's quantity:\n");
        block=getInput<char>("Input block(capital letter):\n");
        shelf=getInput<int>("Input shelf number:\n");
        price=getInput<double>("Input price:\n");
        i.addProduct(type,name,quantity,block,shelf,price,special);
        break;
      }
      case 4:
        {
          
          input=getInput<std::string>("Enter a name or an ID of the product that you which to get the count: \n");
          if (isNumber(input)) 
          {
            int id{convertToInt(input)};
            int count{i.getProductCount(id)};
            if (count>0)
              std::cout << "There are currently " <<count<<" of "<<i.getNameById(id)<<" in the inventory.\n";
            else
              std::cout<<"Invalid ID/NAME!\n\n";
          }
          else
          {
            int count{i.getProductCount(input)};
            if (count>0)
              std::cout << "There are currently " <<count<<" of "<<input<<" in the inventory.\n";
            else
              std::cout<<"There are no current objects of this type!\n\n";
          }
          break;
        }
      case 5:
          std::cout << "There are currently " <<i.getSize()<<" different objects in the inventory.\n";      
          // Code for option 5
          break;
      case 6:
          std::cout << "Your inventory is worth: " <<i.getInventoryValue()<< std::endl;
          // Code for option 6
          break;
      default:
          std::cout << "Invalid option selected. Please select a number between 1 and 8." << std::endl;
          break;
    }
    if (option==0)break;
  }

	return 0;
}
