// Solution for Day 5b for adventofcode.com Puzzles!
// by Alan Estrada
// 
// If programmers don't code Christmas puzzles, Krampus
// will come and delete your github account! Spooky!


#include <iostream>
#include <fstream>
#include <string>

// I know this is bad but this is a casual coding thing
using namespace std;

int hasDoublePair(string str) {
  int pos = 0;
  
  while (pos + 3 <= str.length()) {
    if (str.find(str.substr(pos,2), pos+2) != string::npos) {
      return 1;
    }
    pos++;
  }

  return 0;
}

int main(int argc, char **argv) {
  ifstream fin(argv[1]);

  int numNiceStrings = 0;
  int hasTheThing ;
  string line;

  char prevprevCh, prevCh;

  if (argc != 2) {
    cout << "Incorrect number of args, give me an input file!\n" ;
    return -1;
  }

  if (!fin) {
    cout << "Uh, invalid file bro.\n" ;
    return -1;
  }

  while (getline(fin, line)) {

    hasTheThing = 0;
    prevCh = prevprevCh = 0;

    for(string::iterator iter = line.begin(); iter != line.end(); ++iter) {
      if (!prevprevCh) {
	prevprevCh = *iter;
	continue;
      }

      if (!prevCh) {
	prevCh = *iter;
	continue;
      }

      if (prevprevCh == *iter) {
	hasTheThing++;
	break;
      }

      prevprevCh = prevCh;
      prevCh = *iter;
	
    }

    if (hasTheThing && hasDoublePair(line))
      numNiceStrings++;

  }

  cout << "Ho ho ho! The number of nice strings is " << numNiceStrings << "!" ;
  return 0;
}
