#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getInput(const std::string& prompt) {
    while (true) { // Loop until user enters a valid input
        std::cout << prompt;
        T value{};
        std::cin >> value;

        // Check for failed extraction
        if (!std::cin) { // if the extraction failed
            if (std::cin.eof()) { // if the stream was closed
                exit(0); // shut down the program now
            }

            // Let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input

            std::cout << "Oops, that input is invalid. Please try again.\n";
        } else {
            ignoreLine(); // remove any extraneous input
            return value; // return the successfully read value
        }
    }
}

// Specialization for double to handle decimal numbers
template <>
double getInput<double>(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        double x{};
        std::cin >> x;

        if (!std::cin) {
            if (std::cin.eof()) {
                exit(0);
            }

            std::cin.clear();
            ignoreLine();
            std::cout << "Oops, that input is invalid. Please try again.\n";
        } else {
            ignoreLine();
            return x;
        }
    }
}
// Specialization for bool
template <>
bool getInput<bool>(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;

        // Convert the input to lower case for comparison
        for (auto& ch : input) {
            ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        }
        if (input == "true" || input == "1") {
            ignoreLine();
            return true;
        } else if (input == "false" || input == "0") {
            ignoreLine();
            return false;
        }

        if (std::cin.eof()) {
            exit(0);
        }

        // Input is not recognized as boolean
        std::cin.clear();
        ignoreLine();
        std::cout << "Please enter 'true' or 'false'.\n";
    }
}
void printOptions()
{
  std::cout<<"These are our available functions:"<<"\n";

  std::cout<<"Press 1 to display all products"<<"\n";
  std::cout<<"Press 2 to remove a product"<<"\n";
  std::cout<<"Press 3 to add a new product"<<"\n";
  std::cout<<"Press 4 to get the count of a product"<<"\n";
  std::cout<<"Press 5 to get the size of the inventory"<<"\n";
  std::cout<<"Press 6 to get the total price of the inventory"<<"\n\n";
  std::cout<<"Press 0 to end the program"<<"\n";
}
bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int convertToInt(std::string input)
{
  std::stringstream ss(input);
  int id;
  ss >> id;
  return id;
}
#endif
