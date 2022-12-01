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
