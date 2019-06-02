// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <stack>

using namespace std;


stack<int> stacks[3];// = new stack<int>()[3];

stack<int>& getStack(char ch) { // forgot &
	return stacks[ch - 'a'];
}
char otherChar(char c1, char c2) {
	return 'a' + 'b' + 'c' - c1 - c2;
}

void moveUp(int b, char from, char to) {
	bool recurse = !getStack(from).empty() && getStack(from).top() != b;
	char other = otherChar(from, to);
	int above = b - 1; // not really

	if (recurse) moveUp(above, from, other);

	cout << "(" << b << " -> " << to << ")\n";
	getStack(to).push(getStack(from).top());
	getStack(from).pop();

	//finish recursive
	if (recurse) moveUp(above, other, to);

}

int main() {
	//for (int i = 0; i < 3; i++) stacks[i] = new stack<int>;
	cout << "Insert n: " << endl;
	int n; cin >> n;

	for (int i = n; i>0; i--) getStack('a').push(i);

	cout << "Starting tower process: moves are" << endl;
	moveUp(n, 'a', 'c');

	cout << "done" << endl;
	return 0;
}