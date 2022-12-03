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
