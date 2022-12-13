#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

class Node {
public:
  Node(string n, bool d,Node* location,int s=0) {
    name = n;
    directory = d;
    parent=location;
    size = s;
  };
  Node *parent = NULL;
  Node *getParent() { return parent; }
  void setParent(Node *p) { parent = p; }
  int getSize() { return size; }
  void setSize(int s) { size = s; }
  string getName() { return name; }
  bool isDirectory(){return directory;}
  vector<Node *> getChildren() { return children; }
  void addChild(Node *p) { children.emplace_back(p); }

private:
  string name;
  bool directory;
  int size;
  vector<Node *> children;
};

void print(Node *n) {
  vector<Node *> children = n->getChildren();
  if(!n->isDirectory()){
    for (int i = 0; i < children.size(); i++) {
      print(children.at(i));
    }
  }
  else{
  cout << (n->getName()) << endl;
  }
}
bool isNumber(const std::string &s) {
  return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
  string input;
  // generate map to map each letter to its position
  bool iscommand;
  bool listing = false;
  string command = "  ";
  string folder = "  ";
  Node *location = new Node("/", true,NULL);
  // Read from the text file

  char elemName[15];
  char elemType[15];
  ifstream inputFile("test.txt");
  int level = 0;
  getline(inputFile, input);
  while (getline(inputFile, input)) {

    if (input.rfind("$ cd")==0) {
      sscanf(input.c_str(), "$ cd %s",&folder[0]);
        if (folder.compare("..") != 0) {
          Node newfolder(folder, true,location);
          newfolder.setParent(location);
          location = &newfolder;
          level++;
        } else if (folder.compare("..") == 0) {
          level--;
          location = location->getParent();
        } else {
          level++;
        } 
    }else if (input.rfind("$ ls")==0) {
      listing = true;
    }else {
      sscanf(input.c_str(), "%s %s",elemType,elemName);
      string type=elemType;
      string name=elemName;
      if (isNumber(type)) {
        int size = stoi(type);

        Node newfile=new Node(name, false,location,size);
        location->addChild(&newfile);
      }
    }
  }
  int size = 0;
  print(location);
  inputFile.close();
}
