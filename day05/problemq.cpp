#include <fstream>
#include <iostream>
#include <list>
#include <string.h>
using namespace std;

struct Stack {
  list<string> crates;
  int id;
};

int main() {
  string input;
  // generate map to map each letter to its position

  // Read from the text file
  ifstream inputFile("teststatcks.txt");
  // Use a while loop together with the getline() function to read the file
  // line by line

  while (getline(inputFile, input)) {
    for (int i = 0; i < 3; ++i) {
      cout << scanf("[%s]", input.c_str()) << endl;
    }

    // Close the file
    inputFile.close();
  }
}
