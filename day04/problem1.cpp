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
