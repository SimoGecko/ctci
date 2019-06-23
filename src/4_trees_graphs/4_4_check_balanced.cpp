// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>


using namespace std;

// node structure
struct Node {
	Node(int x, Node* l = nullptr, Node* r = nullptr) : val(x), left(l), right(r) {}

	int val;
	Node *left, *right;
};


//from previous exercise


// Decodes an encoded string to tree.
Node* deserializeTree(string data) {
	if (data == "") return nullptr;

	vector<Node*> TN;
	string s;
	istringstream iss(data);

	while (iss >> s) {
		char* p;
		long val = strtol(s.c_str(), &p, 10);
		if (*p) {
			TN.push_back(nullptr);
		}
		else {
			TN.push_back(new Node(val));
		}
	}

	size_t i = 0, j = 1;
	while (i<TN.size()) {
		if (TN[i]) {
			TN[i]->left = TN[j++];
			TN[i]->right = TN[j++];
		}
		if (j >= TN.size()) break;
		i++;
	}

	return TN[0];
}

//----------------------------------------------



bool isBalanced(Node* node){
	if(node==nullptr) return true;
}


int main() {
	cout << "Checks if a tree is balanced (all subrees heights differ at most 1)." << endl << endl;

	while(true){
		cout << "Insert tree string encoding: " << endl;
		string treeString; getline(cin, treeString); // = "6 4 8 2 5 7 9 1 3";
		Node* root = deserializeTree(treeString);
		cout << "tree is balanced: " << (isBalanced(root)? "yes" : "no") << endl;
	}

	return 0;
}