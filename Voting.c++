// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <sstream>
#include <string>   // string
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>

#include "Voting.h"

using namespace std;

int num_cases;

// ------------
// voting_read
// ------------
vector<Case> voting_read (istream& r)
{
  int cur_candidate, num_candidates, cur_voter, voter_candidate, cur_election, num_ballots;
  string s, b;
  stringstream ballot_line;
  getline( r, s);
  num_cases = stoi( s, nullptr);

  vector<Case> elections( num_cases );
  
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
      elections[ cur_election ].ballots[cur_voter].resize(num_candidates);
      while( getline( ballot_line, b, ' '))
      {
        elections[ cur_election ].ballots[cur_voter][voter_candidate] = stoi( b, nullptr);
        voter_candidate++;
      }
      ballot_line.str("");
      ballot_line.clear();
      cur_voter++;
    }
    elections[ cur_election ].b = cur_voter;

    voting_print(elections[ cur_election ]);

    
  }

  return elections;

}

// ------------
// voting_eval
// ------------
vector<int> voting_eval (Case& c)
{

  vector<int> out_of_the_race(c.n);
  int vote_array[c.n];
  int i, j, max, min;

  while ( true )
  {
    for ( i = 0; i < c.n; i++) vote_array[i] = 0;

    for ( i = 0; i < c.b; ++i )
    {
      j = 0;
      while ( out_of_the_race[ c.ballots[i][j] - 1 ] ) ++j;
      vote_array[ c.ballots[i][j] - 1 ]++;
    }

    max = 0;
    min = 10000;
    for ( j = 0; j < c.n; ++j)
    {
      if ( vote_array[ j ] > max ) max = vote_array[ j ];
      if ( !out_of_the_race[ j ] && vote_array[ j ] < min ) min = vote_array[ j ];
    }

    if( max * 2 > c.b)
    {
      for ( j = 0; j < c.n; ++j )
      {
        if ( vote_array[ j ] < max ) out_of_the_race[ j ] = 1;
      }
      return out_of_the_race;
    }

    if( min == max )
    {
      for ( j = 0; j < c.n; ++j )
      {
        if ( vote_array[ j ] != max ) out_of_the_race[ j ] = 1;
      }
      return out_of_the_race;
    }

    for ( j = 0; j < c.n; ++j )
    {
      if ( vote_array[ j ] == min ) out_of_the_race[ j ] = 1;
    }

  }

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
  vector<Case> Cases= voting_read( r );
  voting_print(Cases[2]);
  
  vector<int> results;

  for ( int i = 0; i < num_cases; ++i)
  {
    results = voting_eval( Cases[i] );
    for ( int j = 0; j < Cases[i].n; ++j)
    {
      if( !results[j])
        printf("%s\n", Cases[i].names[j]);
    }
  }

}
