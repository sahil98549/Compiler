// C++ program to implement DFA based regonizer that accepts
// all strings which follow the language
// L = { letter (letter | digit)* }

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// dfa tells the number associated
// with the present state
int dfa;

// This function is for
// the starting state (zeroth) of DFA
void start(char c)
{
	if (isalpha(c))
		dfa = 1;
	else

// -1 is used to check for any invalid symbol
		dfa = -1;
}

// This function is for the first state of DFA
void state1(char c)
{
	if (isalnum(c))
		dfa = 1;
	else
		dfa = -1;
}

bool DFA_for_ID(string token)
{
	dfa = 0;
	int i, len = token.length();
	for (i = 0; i < len; i++) {
		if (dfa == 0)
			start(token[i]);
		else if (dfa == 1)
			state1(token[i]);
		else
			return 0;
	}
	if (dfa == 1)
		return 1;
	else
		return 0;
}

// driver code
int main()
{
	string input = "Geeks for Geeks is 9ice platfo$m for every1 ";

// to separate all the tokens by space in the string
// and checking for each token
	stringstream ss(input);
	string token;
	while (ss >> token) {
		bool isValid = DFA_for_ID(token);
		if (isValid)
			cout << token << " : "
			     << "Valid" << endl;
		else
			cout << token << " : "
			     << "Invalid" << endl;
	}
	return 0;
}
