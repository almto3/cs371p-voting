// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <>

#include "Voting.h"

using namespace std;

int num_cases;

// ------------
// voting_read
// ------------
Case* voting_read (istream& r)
{
  string s;
  getline( r, s);
  num_cases = atoi( s.c_str() );

  Case * elections[ num_cases ];
  
  getline( r, s); // Skipping blank line

  int current_election = 0;

  while ( getline( r, s) )
  {
    elections[ current_election ]->n = atoi( s.c_str() );

    
  }

}

// ------------
// voting_eval
// ------------
int voting_eval (Case& c)
{

}

// -------------
// voting_print
// -------------
void voting_print (Case& c)
{

}

// -------------
// voting_solve
// -------------
void voting_solve (istream& r, ostream& w)
{
  Case * Cases = voting_read( r );



}

#endif // Voting_h
