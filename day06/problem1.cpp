#include <fstream>
#include <iostream>
#include <list>
#include <string.h>
using namespace std;
void print(list<char> const &vector) {
  for (auto const &i : vector) {
    std::cout << i;
  }
  std::cout << "" << endl;
}
char get(list<char> _list, int _i) {
  list<char>::iterator it = _list.begin();
  for (int i = 0; i < _i; i++) {
    ++it;
  }
  return *it;
}
int main() {
  // generate map to map each letter to its position

  char c;
  int lenght = 4;
  list<char> last4;
  fstream fin("input.txt", fstream::in);
  for (int i = 0; i < 3; i++) {
    fin >> c;
    last4.push_back(c);
  }
  int position = 3;
  int different = 0;
  while (fin >> c && different != 6) {
    different = 0;
    last4.push_back(c);
    for (int i = 0; i < lenght - 1; i++) {
      for (int j = i + 1; j < lenght; j++) {
        if (get(last4, i) != get(last4, j)) {
          different++;
        }
      }
    }
    last4.pop_front();
    last4.resize(3);
    position++;
  }
  cout << position << endl;
}
