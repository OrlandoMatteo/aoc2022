#include <fstream>
#include <iostream>
#include <list>
#include <string.h>
using namespace std;

void print(list<char> const &list) {
  for (auto const &i : list) {
    std::cout << i << std::endl;
  }
}

int main() {
  string input;
  // generate map to map each letter to its position

  // Read from the text file
  ifstream inputFile("stacks.txt");
  list<char> stacks[9];
  char item = '_';
  while (getline(inputFile, input)) {

    if (input == "/n") {
      break;
    }
    // Create stacks of crane
    for (int i = 0; i < 9; i++) {
      item = input.at(i * 4 + 1);
      if (item != ' ') {
        stacks[i].push_front(item);
      }
    }
  }

  // read moves and move cranes
  ifstream movesFile("moves.txt");
  int from = 0;
  int to = 0;
  int amount = 0;
  char crane;
  cout << "\n moving \n";
  while (getline(movesFile, input)) {
    sscanf(input.c_str(), "move %d from %d to %d ", &amount, &from, &to);
    from--;
    to--;
    for (int i = 0; i < amount; i++) {
      // move last from stack [from] to stack [to]
      stacks[to].push_back(stacks[from].back());
      stacks[from].pop_back();
    }
  }
  cout << "\n Moved \n";
  for (int i = 0; i < 9; ++i) {
    cout << "lista : ";
    cout << i << endl;
    print(stacks[i]);
  }
  for (int i = 0; i < 9; ++i) {
    cout << stacks[i].back();
  }
  movesFile.close();
}
