// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <stack>
#include <string>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


stack<int> stacks[3];// = new stack<int>()[3];

stack<int>& getStack(char ch) { // forgot &
	return stacks[ch - 'a'];
}
char otherChar(char c1, char c2) {
	return 'a' + 'b' + 'c' - c1 - c2;
}

void wait(float sec) {
	sleep_for(nanoseconds(1000'000'000*sec));
}

void clearConsole(){
	for (int i = 0; i < 50; ++i) cout << endl;
}

void moveUp(int b, char from, char to) {
	bool recurse = !getStack(from).empty() && getStack(from).top() != b;
	char other = otherChar(from, to);
	int above = b - 1; // not really

	if (recurse) moveUp(above, from, other);

	cout << "(" << b << "->" << to << "), ";
	getStack(to).push(getStack(from).top());
	getStack(from).pop();


	wait(0.2f);

	//finish recursive
	if (recurse) moveUp(above, other, to);

}

int main() {
	//for (int i = 0; i < 3; i++) stacks[i] = new stack<int>;

	string[] mask = {
		{"┌───────────────────────────────────────┐"},
		{"│      |            |            |      │"},
		{"│ {    |    }  {    |    }  {    |    } │"},
		{"│ {    |    }  {    |    }  {    |    } │"},
		{"│ {    |    }  {    |    }  {    |    } │"},
		{"│ {    |    }  {    |    }  {    |    } │"},
		{"│ {    |    }  {    |    }  {    |    } │"},
		{"│      A            B            C      │"},
		{"└───────────────────────────────────────┘"}
	}
		

	for (int i = 5; i>0; i--) getStack('a').push(i);
	cout << "Starting tower process: moves are" << endl;
	moveUp(5, 'a', 'c');

	cout << endl << "done" << endl;
	return 0;
}