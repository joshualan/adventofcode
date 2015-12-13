// Solution for Day 5a for adventofcode.com Puzzles!
// by Alan Estrada
// 
// If programmers don't code Christmas puzzles, Krampus
// will come and delete your github account! Spooky!


#include <iostream>
#include <fstream>
#include <string>

// I know this is bad but this is a casual coding thing
using namespace std;

int isVowel(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return 1;
  }
  return 0;
}

int isNaughty(string str) {
  if (str.find(string("ab")) == string::npos &&
      str.find(string("cd")) == string::npos &&
      str.find(string("pq")) == string::npos &&
      str.find(string("xy")) == string::npos) {
    return 0;
  }
  return 1;
}

int main(int argc, char **argv) {
  ifstream fin(argv[1]);

  int numVowels;
  int hasDouble;
  int numNiceStrings = 0;
  string line;
  char prevCh;

  if (argc != 2) {
    cout << "Incorrect number of args, give me an input file!\n" ;
    return -1;
  }

  if (!fin) {
    cout << "Uh, invalid file bro.\n" ;
    return -1;
  }

  while (getline(fin, line)) {
      numVowels = hasDouble = 0;
      prevCh = 0;

      for(string::iterator iter = line.begin(); iter != line.end(); ++iter) {
	numVowels += isVowel(*iter);

	if (!prevCh)  {
	  prevCh = *iter;
	  continue;
	}
	
	if (prevCh == *iter) {
	  hasDouble++;
	}

	prevCh = *iter;
	
	// Optimization
	if (hasDouble && numVowels == 3) {
	  break;
	}
      }

      if (hasDouble && numVowels >= 3 && !isNaughty(line)) {
	numNiceStrings++;
      }
  }

  cout << "Ho ho ho! The number of nice strings is " << numNiceStrings << "!" ;
  return 0;
}
