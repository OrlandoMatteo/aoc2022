#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
  // generate map to map each letter to its position
  string input;
  vector<vector<int>> grid;
  vector<vector<bool>> visible;
  vector<vector<bool>> Visible;
  ifstream inputFile("input");
  char item = '_';
  int nOfStacks;
  int row = 0;
  int col = 0;
  while (getline(inputFile, input))
  {
    grid.emplace_back();
    visible.emplace_back();
    Visible.emplace_back();
    for (col = 0; col < input.size(); col++)
    {
      // if (col == 0) {
      //   grid.at(row).emplace_back();
      // }
      char c = input.at(col);
      grid.at(row).emplace_back(atoi(&c));
      visible.at(row).emplace_back(true);
      Visible.at(row).emplace_back(false);
    }
    row++;
  }
  bool u = true;
  bool d = true;
  bool l = true;
  bool r = true;
  int visibleCount=0;
  for (int i = 1; i < grid.size() - 1; i++)
  {
    for (int j = 1; j < grid.at(i).size() - 1; j++)
    {
      // check if is visible from the left
      for (int p = 0; p < j; p++)
      {
        if (grid.at(i).at(j) <= grid.at(i).at(p))
        {
          l = false;
        }
      }
      // check if is visible from the right
      for (int p = j + 1; p < grid.at(i).size(); p++)
      {
        if (grid.at(i).at(j) <= grid.at(i).at(p))
        {
          r = false;
        }
      }
      // check if is visible from the top
      for (int p = 0; p < i; p++)
      {
        if (grid.at(i).at(j) <= grid.at(p).at(j))
        {
          u = false;
        }
      }
      // check if is visible from the bottom
      for (int p = i + 1; p < grid.size(); p++)
      {
        if (grid.at(i).at(j) <= grid.at(p).at(j))
        {
          d = false;
        }
      }
      
      visible.at(i).at(j) = u || d || l || r;
      if(visible.at(i).at(j)){
        visibleCount++;
      }
      // cout << visible.at(i).at(j);
      d=true;
      u=true;
      l=true;
      r=true;
    }
    // cout << endl;
  }
  int gridPerimeter = 2 * (grid.size() + grid.at(0).size()-2);
  cout << visibleCount+gridPerimeter << endl;
  return 0;
}
