#include "input.h"
#include "inventory.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Input::handle(Inventory inventory) {
  string input;

  while (input != ".q") {
    // Get lines then tokens
    getline(cin, input);
    vector<string> tokens = this->tokens(input);

    cout << "\033[2J\033[1;1H";
    cout << "-- Corner Grocer's Inventory Manager --" << endl;
    cout << "-- .help for commands --" << endl;

    // Parse the tokens
    // Lowercase first word
    if (tokens.size() > 1) {
      for (char &c : tokens[0]) {
        c = tolower(c);
      }
    }
    if (tokens.size() == 1) {
      // Help Menu
      if (tokens[0] == ".help") {
        cout << "-- Commands --" << endl;
        cout << "-- .q - Terminates the program" << endl;
        cout << "-- list - Displays a list by <item> <num>" << endl;
        cout << "-- histogram - Displays a histogram" << endl;
        cout << "-- <item> - Displays <item> <num>" << endl;
        cout << "-- file <fileName> - Changes the data of items and output file"
             << endl;
        cout << "-- The file format is <item> <newline> item - item must be "
                "capitalized"
             << endl;
        cout << "-- \"default.txt\" is where the program initially gets data "
                "from"
             << endl;
        continue;
      }

      // Display list
      if (tokens[0] == "list") {
        inventory.printItemMenu(0);
        continue;
      }

      // Display file help
      if (tokens[0] == "file") {
        cout << "To set data from file type: file <file>" << endl;
        continue;
      }

      // Display histogram
      if (tokens[0] == "histogram") {
        inventory.printItemMenu(1);
        continue;
      }

      // Uppercase first char to comply with file format
      tokens[0][0] = toupper(tokens[0][0]);
      // Try and find the item and display item and No. of items
      if (inventory.itemExists(tokens[0])) {
        inventory.printItemMenu(tokens[0]);
        continue;
      }
    }
    if (tokens.size() == 2) {
      // Try and set and overwrite data
      if (tokens[0] == "file") {
        if (inventory.setItemsFromFile(tokens[1])) {
          cout << "Data set" << endl;
        }
        continue;
      }
    }
    cout << "Invalid input! Type .help for commands" << endl;
  }
}

// Get tokens from the input string
vector<string> Input::tokens(string input) {
  vector<string> tokens;
  string token;
  // Loop through the string and push chars
  // If char is ' ' then push and clear token while
  // checking to make sure it's not empty
  for (int i = 0; i < input.size(); i++) {
    if (input[i] != ' ') {
      token.push_back(input[i]);
    } else if (!token.empty()) {
      tokens.push_back(token);
      token.clear();
    }
  }

  // Push the final token
  if (!token.empty()) {
    tokens.push_back(token);
  }

  return tokens;
}
