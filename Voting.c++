// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <cstdlib>
#include <cassert>

#include "Voting.h"

using namespace std;

int num_cases;

// ------------
// voting_read
// ------------
Case* voting_read (istream& r)
{
  int cur_candidate, num_candidates, cur_voter, voter_candidate, cur_election;
  string s, b;
  getline( r, s);
  num_cases = stoi( s, nullptr);

  Case * elections[ num_cases ];
  
  getline( r, s); // Skipping blank line

  for ( cur_election = 0; cur_election < num_cases; cur_election++ )
  {
    getline( r, s);
    num_candidates = stoi( s, nullptr;
    elections[ cur_election ]->n = num_candidates;

    for ( cur_candidate = 0; cur_candidate < num_candidates; cur_candidate++ )
    {
      getline( r, s);
      elections[ cur_election ]->names[ cur_candidate ] = s;
    }

    cur_voter = 0;

    while ( getline( r, s) && !s.empty() )
    {
      stringstream ballot_line(s);
      voter_candidate = 0;
      while( getline( ballot_line, b, ' '))
      {
        elections[ current_election ]->ballots[cur_voter][voter_candidate] = stoi(b, nullptr);
        voter_candidate++;
      }
      cur_voter++;
    }
    
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
