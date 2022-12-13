#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

map<char, int> generateAlphabet(string alphastring)
{
  map<char, int> output;
  int counter = 1;
  for (auto c : alphastring)
  {
    output[c] = counter;
    counter++;
  }
  return output;
}

template <typename T>
class Node
{
public:
  Node<T>(T d, int x, int y)
  {
    data = d;
    explored = false;
    parent = NULL;
    this->x = x;
    this->y = y;
  }
  T getData() { return data; }
  bool isUpperNeighbour(Node *N) { return (data - N->getData() == -1 || data - N->getData() == 0); }
  bool isLowerNeighbour(Node *N) { return data - N->getData() >= 0; }
  void addNeighbour(Node *N) { neighbours.emplace_back(N); }
  void setParent(Node *N) { parent = N; }
  Node *getParent() { return parent; }
  void setExplored() { explored = true; }
  bool isExplored() { return explored; }

  vector<Node<T> *> getNeighbours() { return neighbours; }
  int x;
  int y;

private:
  T data;
  vector<Node<T> *> neighbours;
  bool explored;
  Node<T> *parent;
};

void connectGraph(vector<vector<Node<int> *>> graph)
{
  for (int row = 0; row < graph.size() - 1; row++)
  {
    for (int col = 0; col < graph[row].size(); col++)
    {
      if (graph[row][col]->isUpperNeighbour(graph[row + 1][col]))
      {
        graph[row][col]->addNeighbour(graph[row + 1][col]);
      }
      if (graph[row][col]->isLowerNeighbour(graph[row + 1][col]))
      {
        graph[row][col]->addNeighbour(graph[row + 1][col]);
      }
      if (graph[row + 1][col]->isUpperNeighbour(graph[row][col]))
      {
        graph[row + 1][col]->addNeighbour(graph[row][col]);
      }
      if (graph[row + 1][col]->isLowerNeighbour(graph[row][col]))
      {
        graph[row + 1][col]->addNeighbour(graph[row][col]);
      }
    }
    for (int col = 0; col < graph[row].size() - 1; col++)
    {
      if (graph[row][col]->isUpperNeighbour(graph[row][col + 1]))
      {
        graph[row][col]->addNeighbour(graph[row][col + 1]);
      }
      if (graph[row][col]->isLowerNeighbour(graph[row][col + 1]))
      {
        graph[row][col]->addNeighbour(graph[row][col + 1]);
      }
      if (graph[row][col + 1]->isUpperNeighbour(graph[row][col]))
      {
        graph[row][col + 1]->addNeighbour(graph[row][col]);
      }
      if (graph[row][col + 1]->isLowerNeighbour(graph[row][col]))
      {
        graph[row][col + 1]->addNeighbour(graph[row][col]);
      }
    }
  }
  int i = graph.size() - 1;
  for (int col = 0; col < graph[i].size() - 1; col++)
  {
    if (graph[i][col]->isUpperNeighbour(graph[i][col + 1]))
    {
      graph[i][col]->addNeighbour(graph[i][col + 1]);
    }
    if (graph[i][col]->isLowerNeighbour(graph[i][col + 1]))
    {
      graph[i][col]->addNeighbour(graph[i][col + 1]);
    }
    if (graph[i][col + 1]->isUpperNeighbour(graph[i][col]))
    {
      graph[i][col + 1]->addNeighbour(graph[i][col]);
    }
    if (graph[i][col + 1]->isLowerNeighbour(graph[i][col]))
    {
      graph[i][col + 1]->addNeighbour(graph[i][col]);
    }
  }
}
int pathLength(Node<int> *goal)
{
  int length = 0;
  while (goal->getParent() != NULL)
  {
    length++;
    goal = goal->getParent();
  }
  return length;
}
void print(vector<vector<Node<int> *>> graph, map<string, int> start)
{
  // print each row except the last one
  for (int row = 0; row < graph.size() - 1; row++)
  {
    // print each column execpt the last one
    for (int col = 0; col < graph[row].size() - 1; col++)
    {
      cout << setw(3);
      cout << graph[row][col]->getData();
      if (graph[row][col]->isUpperNeighbour(graph[row][col + 1]) || graph[row][col]->isLowerNeighbour(graph[row][col + 1]))
      {
        cout << setw(3);
        cout << "-";
      }
      else
      {
        cout << setw(3);
        cout << " ";
      }
    };
    // print the last column
    cout << setw(3);
    cout << graph[row][graph[row].size() - 1]->getData();
    cout << endl;
    // print the vertical lines
    for (int col = 0; col < graph[row].size(); col++)
    {
      cout << "  ";
      if (graph[row][col]->isUpperNeighbour(graph[row + 1][col]))
      {
        cout << "|";
      }
      else
      {
        cout << " ";
      }
      cout << "   ";
    }
    cout << endl;
  }
  // print the last row
  for (int col = 0; col < graph[0].size(); col++)
  {
    cout << setw(3);
    cout << graph[graph.size() - 1][col]->getData();
    if (graph[graph.size() - 1][col]->isUpperNeighbour(
            graph[graph.size() - 1][col]))
    {
      cout << setw(3);
      cout << "-";
    }
    else
    {
      cout << setw(3);
      cout << " ";
    }
  }
  cout << endl;
};

Node<int> *BFS(vector<vector<Node<int> *>> graph, Node<int> *root,
               Node<int> *goal)
{
  queue<Node<int> *> q;
  root->setExplored();
  q.push(root);
  while (q.size() != 0)
  {
    Node<int> *v = q.front();
    q.pop();
    if (v == goal)
    {
      return v;
    }
    else
    {
      for (auto w : v->getNeighbours())
      {
        if (!w->isExplored())
        {
          cout << w->getData() << "(" << w->x << "," << w->y << ")" << endl;
          w->setExplored();
          w->setParent(v);
          q.push(w);
        }
      }
    }
  }
  return NULL;
}

int main()
{
  string input;
  // generate map to map each letter to its position

  // Read from the text file
  ifstream inputFile("input");
  string alphastring = "abcdefghijklmnopqrstuvwxyz";
  int letterIndex;
  // generate map to map each letter to its position
  map<char, int> alphabet = generateAlphabet(alphastring);
  vector<vector<int>> grid;
  vector<vector<Node<int> *>> ugraph;
  map<string, int> start{{"x", 0}, {"y", 0}};
  map<string, int> end{{"x", 0}, {"y", 0}};
  int row = 0;
  int col = 0;
  while (getline(inputFile, input))
  {
    ugraph.emplace_back();
    col = 0;
    for (auto c : input)
    {
      letterIndex = alphabet[c];
      if (c == 'S')
      {
        start["x"] = col;
        start["y"] = row;
        ugraph[row].emplace_back(new Node<int>(0, col, row));
      }
      else if (c == 'E')
      {
        end["x"] = col;
        end["y"] = row;
        ugraph[row].emplace_back(new Node<int>(26, col, row));
      }
      else
      {
        ugraph[row].emplace_back(new Node<int>(letterIndex, col, row));
      }
      col++;
    }
    row++;
  }
  connectGraph(ugraph);
  // print(ugraph, start);
  Node<int> *root = ugraph[start["y"]][start["x"]];
  Node<int> *goal = ugraph[end["y"]][end["x"]];
  Node<int> *t = BFS(ugraph, root, goal);

  // Close the file
  cout << pathLength(t) << endl;
  inputFile.close();
}
