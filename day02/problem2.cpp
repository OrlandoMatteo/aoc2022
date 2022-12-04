#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main() {
  string input;

  // Read from the text file
  ifstream inputFile("input.txt");

  string elf = "L";
  string me = "M";
  //
  map<string, int> _pointTable{{"A", 1}, {"B", 2}, {"C", 3}};
  map<string, int> XpointTable{{"A", _pointTable["C"]},
                               {"B", _pointTable["A"]},
                               {"C", _pointTable["B"]}};
  map<string, int> ZpointTable{{"A", 6 + _pointTable["B"]},
                               {"B", 6 + _pointTable["C"]},
                               {"C", 6 + _pointTable["A"]}};
  map<string, int> YpointTable{{"A", 3 + _pointTable["A"]},
                               {"B", 3 + _pointTable["B"]},
                               {"C", 3 + _pointTable["C"]}};
  map<string, map<string, int>> mePointTable{
      {"X", XpointTable}, {"Y", YpointTable}, {"Z", ZpointTable}};

  // Use a while loop together w,th the getline() function to read the file line
  // by line
  int score = 0;
  int y = 0;
  while (getline(inputFile, input)) {
    // B Y
    sscanf(input.c_str(), "%s %s", &elf[0], &me[0]);
    cout << elf;
    cout << " ";
    cout << me;
    cout << " ";
    cout << mePointTable[me][elf] << endl;
    score += mePointTable[me][elf];
  }
  // Close the file
  inputFile.close();
  cout << score << endl;
}
