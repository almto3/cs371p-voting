#ifndef Voting_h
#define Voting_h

const int MAX_CANDIDATES = 20;
const int MAX_BALLOTS = 1000;


// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <vector>

using namespace std;

// ------------
// struct Case
// ------------
/**
 * add description
 */

struct Case {
	int n; 												//number of candidates
  int b;                        //number of ballots
	char names [MAX_CANDIDATES][80]; 						//names of candidates
	vector<int> ballots [MAX_BALLOTS]; 		//the ballots
};

// ------------
// voting_read
// ------------
/**
 * read a std input
 * @param r an istream
 * @returns a pointer array of struct Case
 */

vector<Case> voting_read (istream& r);		

// ------------
// voting_eval
// ------------
/**
 * @c is is the instance of the struct Case
 * @returns the winner id in the array of candidates
 */
vector<int> voting_eval (Case& c);

// -------------
// voting_print
// -------------
/**
 * @c is is the instance of the struct Case
 * whatevez
 */
void voting_print (Case& c);

// -------------
// voting_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void voting_solve (istream& r, ostream& w);

#endif // Voting_h
