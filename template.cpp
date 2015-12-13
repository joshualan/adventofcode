// Solution for Day __ for adventofcode.com Puzzles!
// by Alan Estrada
// 
// If programmers don't code Christmas puzzles, Krampus
// will come and delete your github account! Spooky!


#include <iostream>
#include <map>
#include <fstream>

using namespace std;


int main(int argc, char **argv) {
  ifstream fin(argv[1]);

  if (argc != 2) {
    cout << "Incorrect number of args, give me an input file!\n" ;
    return -1;
  }

  if (!fin) {
    cout << "Uh, invalid file bro.\n" ;
  }

  return 0;
}
