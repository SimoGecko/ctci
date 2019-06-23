// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <list>
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

// Encodes a tree to a single string
string serializeTree(Node* root) {
	if (root == nullptr) return "";

	ostringstream ss;

	queue<Node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		Node* node = Q.front(); Q.pop();
		ss << (node == nullptr ? "-" : to_string(node->val)) << " ";

		if (node != nullptr) {
			Q.push(node->left);
			Q.push(node->right);
		}
	}
	cout << ss.str() << endl;
	return ss.str();
}

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



void listOfDepthsRecursive(Node* node, int d, vector<list<Node*>>& ans) {
	if (node == nullptr) return;
	if (ans.size()<d + 1) ans.push_back({});
	ans[d].push_back(node);
	listOfDepthsRecursive(node->left, d + 1, ans);
	listOfDepthsRecursive(node->right, d + 1, ans);
}

void listOfDepthsIterative(Node* root, vector<list<Node*>>& ans){
	if(root==nullptr) return;

	list<Node*> current = {root};
	while(!current.empty){
		ans.push_back(current);
		list<Node*> parent = move(current);
		current.clear();

		for(Node* p : parent){
			if(p->left !=nullptr) current.push_back(p->left );
			if(p->right!=nullptr) current.push_back(p->right);
		}
	}
}

vector<list<Node*>> listOfDepths(Node* root) {
	vector<list<Node*>> ans;
	
	//listOfDepthsRecursive(root, 0, ans); //recursive approach
	listOfDepthsIterative(root, ans); //iterative approach
	
	return move(ans);
}



int main() {
	string treeGraphic = R"(
	       6     
	      / \    
	    4     8  
	   / \   / \ 
	  2   5 7   9
	 / \ 
	1   3
	)";

	const string treeString = "6 4 8 2 5 7 9 1 3";
	Node* root = deserializeTree(treeString);

	auto ans = listOfDepths(root);

	cout << "Lists all nodes at a given depth." << endl << endl;
	cout << treeGraphic << endl;

	for (size_t i = 0; i < ans.size(); ++i) {
		cout << "depth " << i << ":\t";
		for (auto& e : ans[i]) cout << e->val << ", ";
		cout << endl;
	}

	int z; cin >> z;
	return 0;
}