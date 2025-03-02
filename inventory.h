#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
using namespace std;

class Inventory {
private:
  map<string, int> m_items;

public:
  Inventory();
  bool setItemsFromFile(string fileName);
  void printItemMenu(int menuNum);
  void printItemMenu(string item);
  bool itemExists(string itemToCheck);
};

#endif
