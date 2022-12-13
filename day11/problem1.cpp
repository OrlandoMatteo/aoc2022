#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

class Monkey {
public:
  Monkey(vector<int> item, string op1, string op2, int div) {
    for (int i = 0; i < item.size(); i++) {
      startingItems.emplace_back(item[i]);
    }
    operand1 = op1;
    if (op2.rfind("old") != 0) {
      operand2 = stoi(op2);
    }
    divisor = div;
  }

private:
  vector<int> startingItems;
  string operand1;
  string operand2;
  int divisor;
  map<bool, int> throwTo;
};

int main() {

  string input;
  ifstream inputFile("input");
  while (getline(inputFile, input)) {
  }
}
