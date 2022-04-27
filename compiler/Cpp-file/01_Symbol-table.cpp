// C++ program to implement Symbol Table
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

class Node {
	string identifier, scope, type;
	int lineNo;
	Node* next;

public:
	Node() {
		next = NULL;
	}

	Node(string key, string value, string type, int lineNo) {
		this->identifier = key;
		this->scope = value;
		this->type = type;
		this->lineNo = lineNo;
		next = NULL;
	}

	void print() {
		cout << "Identifier's Name:" << identifier
		     << "\nType:" << type
		     << "\nScope: " << scope
		     << "\nLine Number: " << lineNo << "\n";
	}
	friend class SymbolTable;
};

class SymbolTable {
	Node* head[MAX];

public:
	SymbolTable() {
		for (int i = 0; i < MAX; i++)
			head[i] = NULL;
	}

	int hashf(string id); // hash function
	void insert(string id, string scope, string Type, int lineno);

	string find(string id);

	bool deleteRecord(string id);

	void modify(string id, string scope, string Type, int lineno);
};


// Function to modify an identifier
void SymbolTable::modify(string id, string s, string t, int l) {
	int index = hashf(id);
	Node* start = head[index];

	if (start == NULL)
		return ;

	while (start != NULL) {
		if (start->identifier == id) {
			start->scope = s;
			start->type = t;
			start->lineNo = l;
			start->print();
			return;
		}
		start = start->next;
	}

	return; // id not found
}



// Function to delete an identifier
bool SymbolTable::deleteRecord(string id) {
	int index = hashf(id);
	Node* tmp = head[index];
	Node* par = head[index];

	// no identifier is present at that index
	if (tmp == NULL) {
		return false;
	}
	// only one identifier is present
	if (tmp->identifier == id && tmp->next == NULL) {
		tmp->next = NULL;
		delete tmp;
		return true;
	}

	while (tmp->identifier != id && tmp->next != NULL) {
		par = tmp;
		tmp = tmp->next;
	}

	if (tmp->identifier == id && tmp->next != NULL) {
		par->next = tmp->next;
		tmp->next = NULL;
		delete tmp;
		return true;
	}

	// delete at the end
	else {
		par->next = NULL;
		tmp->next = NULL;
		delete tmp;
		return true;
	}
	return false;
}

// Function to find an identifier
string SymbolTable::find(string id) {
	int index = hashf(id);
	Node* start = head[index];

	if (start == NULL)
		return "-1";

	while (start != NULL) {

		if (start->identifier == id) {
			return start->scope;
		}

		start = start->next;
	}

	return "-1"; // not found
}

// Function to insert an identifier
void SymbolTable::insert(string id, string scope, string Type, int lineno) {
	int index = hashf(id);
	Node* p = new Node(id, scope, Type, lineno);

	if (head[index] == NULL) {
		head[index] = p;
		cout << "\n"
		     << id << " inserted";
		cout << " -successfully" << "\n";
		p->print();
		return ;
	}

	else {
		Node* start = head[index];
		while (start->next != NULL)
			start = start->next;

		start->next = p;
		cout << "\n"
		     << id << " inserted";
		cout << " -successfully" << "\n";
		p->print();
		return ;
	} return ;
}

int SymbolTable::hashf(string id) {
	int asciiSum = 0;

	for (int i = 0; i < id.length(); i++) {
		asciiSum = asciiSum + (i + 1) * (id[i] * id.length() % 101) % 101;
	}

	return (asciiSum % 101);
}

// Driver code
int main() {
	SymbolTable st;
	string check;
	cout << "** SYMBOL_TABLE **\n";

	// insert 'if'
	st.insert("if", "local", "keyword", 4);

	//insert while
	st.insert("while", "local", "keyword", 6);

	// insert 'number'
	st.insert("number", "global", "variable", 2);

	// insert 'another number'
	st.insert("number", "local", "variable", 10);


	// find 'if'
	check = st.find("if");
	if (check != "-1")
		cout << "\nif Identifier is present\n";
	else
		cout << "\nIdentifier Not Present\n";


	// delete 'if'
	if (st.deleteRecord("if"))
		cout << "\nif Identifier is deleted" << "\n";
	else
		cout << "\nFailed to delete\n";


	// modify 'number'
	cout << "\nNumber Identifier updated\n";
	st.modify("number", "global", "variable", 3);

	return 0;
}