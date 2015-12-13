// Solution for Day 3b for adventofcode.com Puzzles!
// by Alan Estrada
// 
// If programmers don't code Christmas puzzles, Krampus
// will come and delete your github account! Spooky!

#include <iostream>
#include <map>
#include <fstream>

using namespace std;
// I used C++ because maps work perfectly for this!

int main(int argc, char **argv) {
  ifstream fin(argv[1]);
  map<int, map<int,int> > santasPath; // Is this how Skynet begins?
                                      // What have you wrought on us, Santa?

  char dir;
  int count = 0, numHouses = 1;

  int robotX = 0, robotY = 0, realX = 0, realY = 0, *x,  *y;

  if (argc != 2) {
    cout << "Incorrect number of args, give me an input file!\n";
    return -1;
  }

  if (!fin) {
    cout << "Uh, invalid file bro.\n";
    return -1;
  }

  santasPath[0][0]++;  

  while (fin >> dir) {
    
    // If it's odd
    if (count++ % 2) { 
      x = &robotX;
      y = &robotY;
    }
    // If it's even
    else { 
      x = &realX;
      y = &realY;
    }

    if (dir == '^') {
      ++*y;
    }
    else if (dir == 'v') {
      --*y;
    }
    else if (dir == '>') {
      ++*x;
    }
    else if (dir == '<') {
      --*x;
    }

    // If it's the first time we visited this house, then
    // log in.
    if (!santasPath[*x][*y]++) {
      numHouses++;
    }
  }
  cout << "Santa and his robotic compatriot have visited " << numHouses << " lucky houses this year!" << endl;

  return 0;
}
