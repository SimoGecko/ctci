// (c) Simone Guggiari 2019 - CTCI
#include <iostream>

using namespace std;

struct BN {
	BN *left, *right;
	char data;

	BN(char d, BN* l = nullptr, BN* r = nullptr) : data(d), left(l), right(r) {}
};

// O---O  O  O---O
// l  lm  n  rm  r
void LinkifyRecursive(BN* node, BN** lmost, BN** rmost) {
	if (node == nullptr) { *lmost = *rmost = nullptr; return; }

	BN **lm, **rm, **l, **r;
	lm = rm = l = r = nullptr;

	LinkifyRecursive(node->left, l, lm);
	LinkifyRecursive(node->right, rm, r);

	node->left = *lm;
	node->right = *rm;
	if (rm != nullptr) (*rm)->left  = node;
	if (lm != nullptr) (*lm)->right = node;

	if (lmost != nullptr) *lmost = (*l == nullptr) ? node : *l;
	if (rmost != nullptr) *rmost = (*r == nullptr) ? node : *r;
}

void Linkify(BN* root) {
	BN **head, **tail;
	head = tail = nullptr;
	LinkifyRecursive(root, head, tail);
}


int main() {
	//create
	BN d('d'), e('e'), f('f');
	BN b('b', &d, &e), c('c', &f, nullptr);
	BN a('a', &b, &c);

	Linkify(&a);

	cout << "done" << endl;

	return 0;
}