// Solution for Day 3a for adventofcode.com Puzzles!
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
  map<int, map<int,int> > santaPath;
  char dir;
  map<int, map<int, int> >::iterator iter;

  int numHouses = 0;

  int x = 0, y = 0;

  if (argc != 2) {
    printf( "Incorrect number of args, give me an input file!\n");
    return -1;
  }

  if (!fin) {
    printf("Uh, invalid file bro.\n");
  }

  santaPath[x][y]++;  

  while (fin >> dir) {
    if (dir == '^') {
      y++;
    }
    else if (dir == 'v') {
      y--;
    }
    else if (dir == '>') {
      x++;
    }
    else if (dir == '<') {
      x--;
    }
    santaPath[x][y]++;
  }

  for (iter = santaPath.begin();  iter != santaPath.end(); iter++) {
    numHouses += iter->second.size();
  }

  cout << "Santa has visited " << numHouses << " lucky houses this year!" << endl;

  return 0;
}
