#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

struct Elem {
  string parent;
  string name;
  bool directory;
  int size;
}; 

bool isNumber(const std::string &s) {
  return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int getSize(Elem e){
  if(e.directory){
    return 0
  }
}

int main() {
  string input;
  // generate map to map each letter to its position
  bool iscommand;
  bool listing = false;
  string command = "  ";
  string folder = "  ";
  string location = "  ";
  map<string,Elem> tree;
  // Read from the text file

  string elemName;
  string type;
  ifstream inputFile("test.txt");
  int level = 0;
  while (getline(inputFile, input)) {
    if (input[0] == '$') {
      listing = false;
    }
    if (!listing) {
      sscanf(input.c_str(), "$ %s %s", &command[0], &folder[0]);
      if (command.compare("cd") == 0) {
        if (folder.compare("..") != 0) {
          Elem newfolder;
          newfolder.directory = true;
          newfolder.size = 0;
          newfolder.parent = location;
          newfolder.name = folder;
          tree[folder]=newfolder;
          location = folder;
          listing = false;
          level++;
        } else if (folder.compare("..") == 0) {
          level--;
          listing = false;
        } else {
          level++;
          listing = false;
        }
      } else {
        listing = true;
      }
    } else {
      stringstream ss(input);
      ss >> type >> elemName;
      if (isNumber(type)) {
        int size = stoi(type);
        Elem file;
        file.directory = false;
        file.size = size;
        file.parent = location;
        file.name = elemName;
        tree[elemName]=file;
      } else {
      }
    }
  }
  int size = 0;
  for (auto &itr:tree){
    string name=itr.second.name;
    cout<<name<<endl;
    for (auto &j:tree){
      if(j.second.parent.compare(name)==0){

      }
      
    }
  }
  inputFile.close();
}
