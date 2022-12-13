#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
  string input;
  // generate map to map each letter to its position

  // Read from the text file

  ifstream inputFile("input");

  int X = 1;
  int operation=0;
  int stops[6] = {20, 60, 100, 140, 180, 220};
  int stopIndex = 0;
  int signalStrength = 0;
  vector<int> reg;
  vector<int> inst;
  while (getline(inputFile, input))
  {
    // read input
    if (input.rfind("addx") == 0)
    {
      sscanf(input.c_str(), "addx %d", &operation);
      inst.emplace_back(0);
      inst.emplace_back(operation);
    }
    else
    {
      inst.emplace_back(0);
    }

  }
  for (int i = 0; i < inst.size(); i++)
  {
    if (i+1 == stops[stopIndex])
    {
      cout << "cycle :" << i+1 << endl;
      
      cout <<"X: "<<X<<endl;
      cout << (i +1) * X << endl;
      signalStrength += (i+1 ) * X ;
      stopIndex++;
    }
    X+=inst[i];
  }
  cout<<signalStrength<<endl;
}
