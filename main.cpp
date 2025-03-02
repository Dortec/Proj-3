#include "input.h"
#include "inventory.h"
#include <iostream>
using namespace std;

int main() {
  // Clear and setup menu
  cout << "\033[2J\033[1;1H";
  cout << "-- Corner Grocer's Inventory Manager --" << endl;
  cout << "-- .help for commands --" << endl;

  // Initalize and handle input
  Inventory inventory;
  Input input;
  input.handle(inventory);

  // Goodbye Message
  cout << "\033[2J\033[1;1H";
  cout << "-- Corner Grocer's Inventory Manager --" << endl;
  cout << "-- Goodbye! --" << endl;

  return 0;
}
