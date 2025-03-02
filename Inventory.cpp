#include "inventory.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

Inventory::Inventory() { setItemsFromFile("default.txt"); }

bool Inventory::setItemsFromFile(string fileName) {
  fstream inputFile;
  ofstream outputFile;
  string item;

  // Open file and check if ok
  inputFile.open(fileName);

  if (!inputFile) {
    cerr << "File " << fileName << " did not open or does not exist!" << endl;
    return false;
  }

  // Clear items
  m_items.clear();

  // While the input file can provide items
  while (inputFile >> item) {
    // Increment the value in key
    m_items[item]++;
  }

  inputFile.close();

  // Create backup file and make sure it's empty
  outputFile.open("frequency.dat");
  outputFile.clear();

  // Adds <item> <num> <newline> to output file
  for (auto &item : m_items) {
    outputFile << item.first << " " << item.second << "\n";
  }

  outputFile.close();
  return true;
}

// Iterate and returns true if it finds item
bool Inventory::itemExists(string itemToCheck) {
  for (auto &item : m_items) {
    if (item.first == itemToCheck) {
      return true;
    }
  }
  return false;
}

// Prints various menus
void Inventory::printItemMenu(int menuNum) {
  switch (menuNum) {
  case 0: {
    // <item> <numItems>
    for (auto &item : m_items) {
      cout << item.first << " " << item.second << endl;
    }
    break;
  }
  case 1: {
    // <item> <starline>
    for (auto &item : m_items) {
      string starLine;
      for (int i = 0; i < item.second; i++) {
        starLine.push_back('*');
      }

      cout << item.first << " " << starLine << endl;
    }
    break;
  }
  }
}

void Inventory::printItemMenu(string item) {
  cout << "Number of " << item << ": " << m_items.at(item) << endl;
}
