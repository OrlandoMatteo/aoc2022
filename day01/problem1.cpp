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
