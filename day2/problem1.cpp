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
  map<string, int> _pointTable{{"X", 1}, {"Y", 2}, {"Z", 3}};
  map<string, int> XpointTable{{"A", 3 + _pointTable["X"]},
                               {"B", _pointTable["X"]},
                               {"C", 6 + _pointTable["X"]}};
  map<string, int> YpointTable{{"A", 6 + _pointTable["Y"]},
                               {"B", 3 + _pointTable["Y"]},
                               {"C", _pointTable["Y"]}};
  map<string, int> ZpointTable{{"A", _pointTable["Z"]},
                               {"B", 6 + _pointTable["Z"]},
                               {"C", 3 + _pointTable["Z"]}};
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
