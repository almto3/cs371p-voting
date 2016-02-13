// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <sstream>
#include <string>   // string
#include <cstdlib>
#include <cassert>
#include <cstring>

#include "Voting.h"

using namespace std;

int num_cases;

// ------------
// voting_read
// ------------
Case* voting_read (istream& r)
{
  int cur_candidate, num_candidates, cur_voter, voter_candidate, cur_election, num_ballots;
  string s, b;
  stringstream ballot_line;
  getline( r, s);
  num_cases = stoi( s, nullptr);

  Case elections[ num_cases ];
  
  getline( r, s); // Skipping blank line

  for ( cur_election = 0; cur_election < num_cases; cur_election++ )
  {
    getline( r, s);
    num_candidates = stoi( s, nullptr);
    elections[ cur_election ].n = num_candidates;

    for ( cur_candidate = 0; cur_candidate < num_candidates; cur_candidate++ )
    {
      getline( r, s);
      strncpy(elections[ cur_election ].names[ cur_candidate ], s.c_str(), 80);
    }

    cur_voter = 0;

    while ( getline( r, s) && !s.empty() )
    {

      ballot_line<<s;
      voter_candidate = 0;
      while( getline( ballot_line, b, ' '))
      {
        elections[ cur_election ].ballots[cur_voter][voter_candidate] = stoi(b, nullptr);
        voter_candidate++;
      }
      ballot_line.str("");
      ballot_line.clear();
      cur_voter++;
    }
    elections[ cur_election ].b = cur_voter;
    
  }

  return elections;

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

  printf("num_candidates: %d\n", c.n);
  printf("num_ballots: %d\n", c.b);

  for( int i = 0; i < c.n; i++)
  {
    printf("%s\n", c.names[i]);
  }

  for( int i = 0; i < c.b; i++)
  {
    for( int j = 0; j < c.n; j++)
    {
      printf("%d ", c.ballots[i][j]);
    }
    printf("\n");
  }



  return;
  
}

// -------------
// voting_solve
// -------------
void voting_solve (istream& r, ostream& w)
{
  Case * Cases = voting_read( r );

  voting_print(Cases[1]);



}
