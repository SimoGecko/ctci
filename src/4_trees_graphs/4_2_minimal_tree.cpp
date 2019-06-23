// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node(int x, Node* l = nullptr, Node* r = nullptr) : val(x), left(l), right(r) {}

	int val;
	Node *left, *right;
};



Node* BuildBinarySearchTtree(const vector<int>& A, int l = -1, int r = -1) {
	if (l>r) return nullptr;

	if (l == -1 && r == -1) {
		l = 0;
		r = A.size() - 1;
	}

	int n = (r + l + 1) / 2;

	Node* leftNode = BuildBinarySearchTtree(A, l, n - 1);
	Node* rightNode = BuildBinarySearchTtree(A, n + 1, r);
	return new Node(A[n], leftNode, rightNode);
}




int main() {
	vector<int> A = { 1,2,3,4,5,6,7,8,9 };
	Node* root = BuildBinarySearchTtree(A);


	return 0;
}