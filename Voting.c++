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
  int cur_candidate, num_candidates, cur_voter, voter_candidate, cur_election;
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
    elections[ cur_election ].names.resize( num_candidates );

    for ( cur_candidate = 0; cur_candidate < num_candidates; cur_candidate++ )
    {
      getline( r, s);
      elections[ cur_election ].names[cur_candidate] = s;
    }

    cur_voter = 0;
    //elections[ cur_election ].ballots.resize(1000);

    while ( getline( r, s) && !s.empty() )
    {

      ballot_line<<s;
      voter_candidate = 0;
      vector<int> r;
      //elections[ cur_election ].ballots[cur_voter].resize(num_candidates);
      while( getline( ballot_line, b, ' '))
      {
        r.push_back(stoi( b, nullptr));
        //elections[ cur_election ].ballots[cur_voter].push_back(stoi( b, nullptr));
        voter_candidate++;
      }
      elections[ cur_election ].ballots.push_back(r);
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
vector<int> voting_eval (Case& c)
{
  vector<int> out_of_the_race(c.n);
  vector<vector<int>> voter_list[c.n];
  int vote_array[c.n];
  int i, j, max, min;

  while ( true )
  {
    for ( i = 0; i < c.n; i++) vote_array[i] = 0;

    //for ( i = 0; i < c.ballots.size(); ++i )
    while(c.ballots.size())
    {
      j = 0;
  //    printf("Size: %d Ballots: %d values: %d\n", out_of_the_race.size(), c.ballots.size(), c.ballots.at(0).at(j)-1);
      while ( out_of_the_race[ c.ballots.at(0).at(j) - 1 ] ) ++j;
      voter_list[ c.ballots.at(0).at(j) - 1 ].push_back(c.ballots.at(0) );
      c.ballots.erase( c.ballots.begin() );
    }

    max = 0;
    min = 10000;
    for ( j = 0; j < c.n; ++j)
    {
//    printf("Vote_size: %d %d\n", j, voter_list[j].size());
      if ( voter_list[j].size() > max ) max = voter_list[j].size();
      if ( !out_of_the_race[ j ] && voter_list[j].size() < min ) min = voter_list[j].size();
    }

    if( max * 2 > c.b)
    {
      for ( j = 0; j < c.n; ++j )
      {
        if ( voter_list[j].size() < max ) out_of_the_race[ j ] = 1;
      }
      return out_of_the_race;
    }

    if( min == max )
    {
      for ( j = 0; j < c.n; ++j )
      {
        if ( voter_list[j].size() != max ) out_of_the_race[ j ] = 1;
      }
      return out_of_the_race;
    }

    for ( j = 0; j < c.n; ++j )
    {
      if ( voter_list[j].size() == min )
      {
        out_of_the_race[ j ] = 1;
        c.ballots.insert( c.ballots.end(), voter_list[j].begin(), voter_list[j].end() );
      }
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
//    printf("%s\n", c.names[i]);
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

  vector<int> results;

  for ( int i = 0; i < num_cases; ++i)
  {
    results = voting_eval( Cases[i] );
    for ( int j = 0; j < Cases[i].n; ++j)
    {
      if( !results[j])
        w << Cases[i].names[j] << endl;
        //printf("%s\n", Cases[i].names[j]);
    }
    if(i < num_cases-1) w << endl;
  }

}
