# AOC2022
## day01
### problem1 
```cpp
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
  string input;

  // Read from the text file
  ifstream inputFile("input.txt");
  string lineEnd("");

  int maxCalories = 0;
  int elfCalories = 0;
  int lineCalories = 0;
  // Use a while loop together with the getline() function to read the file line
  // by line
  while (getline(inputFile, input)) {
    if (input.compare(lineEnd) != 0) {
      lineCalories = stoi(input);
      elfCalories += lineCalories;
    } else {
      if (elfCalories > maxCalories) {
        maxCalories = elfCalories;
      }
      elfCalories = 0;
    }
  }
  // Close the file
  inputFile.close();
  cout << maxCalories << endl;
}
```
### problem2 
```cpp
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
  string input;

  // Read from the text file
  ifstream inputFile("input.txt");
  string lineEnd("");

  int top3 = 0;
  int top2 = 0;
  int top1 = 0;
  int elfCalories = 0;
  int lineCalories = 0;
  // Use a while loop together with the getline() function to read the file line
  // by line
  while (getline(inputFile, input)) {
    if (input.compare(lineEnd) != 0) {
      lineCalories = stoi(input);
      elfCalories += lineCalories;
    } else {
      if (elfCalories > top3) {
        if (elfCalories > top2) {
          if (elfCalories > top1) {
            top3 = top2;
            top2 = top1;
            top1 = elfCalories;
          } else {
            top3 = top2;
            top2 = elfCalories;
          }
        } else {
          top3 = elfCalories;
        }
      }
      elfCalories = 0;
    }
  }

  // Close the file
  inputFile.close();
  cout << top1 << endl;
  cout << top2 << endl;
  cout << top3 << endl;
  cout << top1 + top2 + top3 << endl;
}
```
## day02
### problem1 
```cpp
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
```
### problem2 
```cpp
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
```
## day03
### problem1 
```cpp
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

map<char, int> generateAlphabet(string alphastring) {
  map<char, int> output;
  int counter = 0;
  for (auto c : alphastring) {
    output[c] = counter;
    counter++;
  }
  return output;
}

int main() {
  string input;
  string alphastring = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // generate map to map each letter to its position
  map<char, int> alphabet = generateAlphabet(alphastring);

  // Read from the text file
  ifstream inputFile("input.txt");
  int lenString;
  int stop;
  bitset<52> first(0);
  bitset<52> second(0);
  int letterIndex;
  int priority = 0;
  int prioritySum = 0;
  int k = 0;
  // Use a while loop together with the getline() function to read the file line
  // by line

  while (getline(inputFile, input) && k < 10) {

    lenString = input.length();
    stop = lenString / 2;
    string Sfirst = input.substr(0, stop);
    string Ssecond = input.substr(stop);
    for (auto c : Sfirst) {
      letterIndex = alphabet[c];
      first.set(letterIndex, 1);
    }
    for (auto c : Ssecond) {
      letterIndex = alphabet[c];
      second.set(letterIndex, 1);
    }

    bitset<52> output = 0;
    output = first & second;
    priority = output._Find_first() + 1;

    prioritySum += priority;
    first.reset();
    second.reset();
  }
  cout << prioritySum;
  cout << "\n";

  // Close the file
  inputFile.close();
}
```
### problem2 
```cpp
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

map<char, int> generateAlphabet(string alphastring) {
  map<char, int> output;
  int counter = 0;
  for (auto c : alphastring) {
    output[c] = counter;
    counter++;
  }
  return output;
}

int main() {
  string input;
  string alphastring = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // generate map to map each letter to its position
  map<char, int> alphabet = generateAlphabet(alphastring);

  // Read from the text file
  ifstream inputFile("input.txt");
  int lenString;
  int stop;
  bitset<52> line(0);
  bitset<52> temp;
  temp.set();
  int letterIndex;
  int priority = 0;
  int prioritySum = 0;
  int k = 0;
  // Use a while loop together with the getline() function to read the file line
  // by line

  while (getline(inputFile, input)) {
    for (auto c : input) {
      letterIndex = alphabet[c];
      line.set(letterIndex, 1);
    }

    temp &= line;
    k++;
    line.reset();
    if (k == 3) {
      priority = temp._Find_first() + 1;
      prioritySum += priority;
      temp.set();
      k = 0;
    }
  }
  cout << prioritySum;
  cout << "\n";

  // Close the file
  inputFile.close();
}
```
## day04
### problem1 
```cpp
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main() {
  string input;
  // generate map to map each letter to its position

  // Read from the text file
  ifstream inputFile("input.txt");
  // Use a while loop together with the getline() function to read the file line
  // by line
  int elfA[2] = {0, 0};
  int elfB[2] = {0, 0};
  int pairs = 0;
  while (getline(inputFile, input)) {
    sscanf(input.c_str(), "%d-%d,%d-%d", &elfA[0], &elfA[1], &elfB[0],
           &elfB[1]);
    if (((elfA[0] <= elfB[0]) && (elfA[1] >= elfB[1])) ||
        ((elfA[0] >= elfB[0]) && (elfA[1] <= elfB[1]))) {
      char buffer[50];
      sprintf(buffer, "%d-%d,%d,%d", elfA[0], elfA[1], elfB[0], elfB[1]);
      cout << buffer << endl;
      pairs++;
    }
  }

  // Close the file
  cout << pairs << endl;
  inputFile.close();
}
```
### problem2 
```cpp
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main() {
  string input;
  // generate map to map each letter to its position

  // Read from the text file
  ifstream inputFile("input.txt");
  // Use a while loop together with the getline() function to read the file line
  // by line
  int elfA[2] = {0, 0};
  int elfB[2] = {0, 0};
  int pairs = 0;
  int k = 0;
  while (getline(inputFile, input)) {
    sscanf(input.c_str(), "%d-%d,%d-%d", &elfA[0], &elfA[1], &elfB[0],
           &elfB[1]);
    char buffer[50];
    if ((elfA[0] <= elfB[0] && elfA[1] >= elfB[0]) ||
        (elfA[0] <= elfB[1] && elfA[1] >= elfB[1]) ||
        (elfA[0] >= elfB[0] && elfA[0] <= elfB[1]) ||
        (elfA[1] >= elfB[0] && elfA[1] <= elfB[1])) {
      // sprintf(buffer, "%d-%d,%d-%d", elfA[0], elfA[1], elfB[0], elfB[1]);
      pairs++;
    }
    k++;
  }

  // Close the file
  cout << pairs << endl;
  inputFile.close();
}
```
