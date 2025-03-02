#ifndef INPUT_H
#define INPUT_H

#include "inventory.h"
#include <string>
#include <vector>

class Input {
private:
  // Tokens seperated by ' '
  std::vector<std::string> tokens(std::string input);

public:
  void handle(Inventory inventory);
};

#endif
