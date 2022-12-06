#include <fstream>
#include <iostream>
#include <list> #include <string.h> #include <vector>
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
  ifstream inputFile("input.txt");
  vector<list<char>> stacks;
  char item = '_';
  int nOfStacks;
  while (getline(inputFile, input)) {
    // if no element are in the vector of stacks we create as many empty stack
    // as needed
    if (stacks.size() == 0) {
      nOfStacks = input.size() / 4 + 1;
      for (int i = 0; i < nOfStacks; i++) {
        stacks.emplace_back();
      }
    }
    // if the second element is a number it means we parsed all the stacks so we
    // trash the empty line and break;
    if (input[1] == '1') {
      getline(inputFile, input);
      break;
    }
    // Create stacks of crane
    int i = 0;
    while (i * 4 + 1 < input.size()) {
      item = input.at(i * 4 + 1);
      if (item != ' ') {
        stacks[i].push_front(item);
      }
      i++;
    }
  }

  // read moves and move cranes
  int from = 0;
  int to = 0;
  int amount = 0;
  char crane;
  while (getline(inputFile, input)) {
    sscanf(input.c_str(), "move %d from %d to %d ", &amount, &from, &to);
    from--;
    to--;
    for (int i = 0; i < amount; i++) {
      // move last from stack [from] to stack [to]
      stacks[to].push_back(stacks[from].back());
      stacks[from].pop_back();
    }
  }
  cout << "last item on stacks" << endl;
  for (int i = 0; i < nOfStacks; ++i) {
    cout << stacks[i].back();
  }
  inputFile.close();
}
