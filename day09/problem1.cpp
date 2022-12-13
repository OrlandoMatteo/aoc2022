#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

class Point {
public:
  Point(int X, int Y) {
    x = X;
    y = Y;
  }
  int x;
  int y;
  int distanceX(Point *other) { return abs(x - other->x); }
  int distanceY(Point *other) { return abs(y - other->y); }
  bool isNearX(Point *other) { return distanceX(other) < 2; }
  bool isNearY(Point *other) { return distanceY(other) < 2; }
  void moveUp() { y++; }
  void moveDown() { y--; }
  void moveRight() { x++; }
  void moveLeft() { x--; }
};

void MoveUp(Point *head, Point *tail, map<int, map<int, bool>> *visited) {
  head->moveUp();
  if (!tail->isNearY(head)) {
    tail->moveUp();
    if (head->x - tail->x == -1) {
      // .H.
      // ...
      // ..T
      tail->moveLeft();
    } else if (head->x - tail->x == 1) {
      // .H.
      // ...
      // T..
      tail->moveRight();
    }
  }
}

void MoveDown(Point *head, Point *tail, map<int, map<int, bool>> *visited) {
  head->moveDown();
  if (!tail->isNearY(head)) {
    tail->moveDown();
    if (head->x - tail->x == -1) {
      tail->moveLeft();
    } else if (head->x - tail->x == 1) {
      tail->moveRight();
    }
  }
}

void MoveRight(Point *head, Point *tail, map<int, map<int, bool>> *visited) {
  head->moveRight();
  if (!tail->isNearX(head)) {
    tail->moveRight();
    if (head->y - tail->y == -1) {
      tail->moveDown();
    } else if (head->y - tail->y == 1) {
      tail->moveUp();
    }
  }
}

void MoveLeft(Point *head, Point *tail, map<int, map<int, bool>> *visited) {
  head->moveLeft();
  if (!tail->isNearX(head)) {
    tail->moveLeft();
    if (head->y - tail->y == -1) {
      tail->moveDown();
    } else if (head->y - tail->y == 1) {
      tail->moveUp();
    }
  }
}

int main() {
  string input;
  // generate map to map each letter to its position

  // Read from the text file

  map<int, map<int, bool>> visited;
  ifstream inputFile("input");
  Point head(0, 0);
  Point tail(0, 0);
  // map direction to integer
  map<string, int> Direction;
  Direction["U"] = 0;
  Direction["D"] = 1;
  Direction["L"] = 2;
  Direction["R"] = 3;

  string direction = " ";
  char *c_steps;
  int steps = 0;
  while (getline(inputFile, input)) {
    sscanf(input.c_str(), "%s %d", &direction[0], &steps);

    switch (Direction[direction]) {
    case 0:
      for (int i = 0; i < steps; i++) {
        MoveUp(&head, &tail, &visited);
        visited[(&tail)->x][(&tail)->y] = true;
      }
      break;
    case 1:
      for (int i = 0; i < steps; i++) {
        MoveDown(&head, &tail, &visited);
        visited[(&tail)->x][(&tail)->y] = true;
      }
      break;
    case 2:
      for (int i = 0; i < steps; i++) {
        MoveLeft(&head, &tail, &visited);
        visited[(&tail)->x][(&tail)->y] = true;
      }
      break;
    case 3:
      for (int i = 0; i < steps; i++) {
        MoveRight(&head, &tail, &visited);
        visited[(&tail)->x][(&tail)->y] = true;
      }
      break;
    }
    
  }
  // print the map
  int placeVisited=0;
  for (auto it = visited.begin(); it != visited.end(); it++) {
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      placeVisited++;
    }
  }
  cout << placeVisited << endl;
  inputFile.close();
}
