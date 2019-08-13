/************************************************************************
//
//  Filename: .cpp
//
//  Code Description:
//
//  Created by brucederland on xx/xx/19.
//
************************************************************************/

#include <iostream> /* basic input output*/
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

/* Must put struct in the begining */
struct Candidate
{
	string firstName;
	string lastName;
	int votes;
	double pScore;
};	/* struct ends with semicolon*/

const int ARR_SIZE = 100;

void readFile(Candidate[]);
/*
void displayList(Candidate[]);
void sortByVotes(Candidate[]);
void displayCandidate(Candidate);
Candidate getWinner(Candidate[]);
Candidate getLast(Candidate[]);
void calculateScores(Candidate[]);
*/

int main()
{
	Candidate candidates[ARR_SIZE];
	ifstream infile;
	readFile(candidates);
}

void readFile(Candidate candidates[])
{
	string line;
	ifstream infile;
	int structIndex;
	infile.open("data.txt");
   	if (infile.fail())
	{ // check if file is opened successfully
      // file opening failed
      cout << "Error Opening file ... " << endl;
    }
	while (!infile.eof())
	{
		getline(infile, line);
		// code goes here, don't modify the provided code
		infile >> candidates[structIndex].firstName>> candidates[structIndex].lastName>> candidates[structIndex].votes;
		structIndex++;
	}
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout<<line<<endl;
	}
	infile.close();
}

/*
void displayList(Candidate candidates[]) {}
void sortByVotes(Candidate candidates[]) {}
void displayCandidate(Candidate cand) {}
Candidate getWinner(Candidate candidates[]) {}
Candidate getLast(Candidate candidates[]) {}
void calculateScores(Candidate candidates[]) {}
*/