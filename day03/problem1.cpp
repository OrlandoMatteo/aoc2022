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
