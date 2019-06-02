// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string t9[]{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
const vector<string> words{
	"a", "about", "all", "also", "and", "as", "at", "be", "because", "but", "by", "can", "come", "could", "day", "do", "even", "find",
	"first", "for", "from", "get", "give", "go", "have", "he", "her", "here", "him", "his", "how", "i", "if", "in", "into", "it", "its",
	"just", "know", "like", "look", "make", "man", "many", "me", "more", "my", "new", "no", "not", "now", "of", "on", "one", "only", "or",
	"other", "our", "out", "people", "say", "see", "she", "so", "some", "take", "tell", "than", "that", "the", "their", "them", "then",
	"there", "these", "they", "thing", "think", "this", "those", "time", "to", "two", "up", "use", "very", "want", "way", "we", "well",
	"what", "when", "which", "who", "will", "with", "would", "year", "you", "your"
};

const vector<string> dial{
	"+-----+-----+-----+",
	"|  1  |  2  |  3  |",
	"|     | abc | def |",
	"+-----+-----+-----+",
	"|  4  |  5  |  6  |",
	"| ghi | jkl | mno |",
	"+-----+-----+-----+",
	"|  7  |  8  |  9  |",
	"| pqrs| tuv | wxyz|",
	"+-----+-----+-----+"
};

char char2idx[26];

void setupIndices() {
	for (int i = 0; i<10; i++) {
		for (auto c : t9[i]) char2idx[c - 'a'] = i;
	}
}

class Node {
public:
	Node * const childFromChar(char c) { // a..z
		return safeChild(char2idx[c - 'a'] - 2);
	}

	Node* const childFromDigit(char d) { // 0..9
		return safeChild(d - 2);
	}

	void setChildFromChar(char c, Node* n) { _cs[char2idx[c - 'a'] - 2] = n; }

	void addWord(const string& word) { _ws.push_back(word); }
	const vector<string>& words() { return _ws; }

private:
	Node * safeChild(int idx) {
		if (0 <= idx && idx<8) return _cs[idx];
		return nullptr;
	}
	Node* _cs[8];
	vector<string> _ws;
};



Node root;


void processWords(const vector<string>& words) {
	//creates the appropriate DS given the words
	for (auto w : words) {
		Node* current = &root;
		for (auto c : w) {
			if (!('a' <= c && c <= 'z')) {
				cout << "Erroneous char: " << c << endl;
				return;
			}

			if (current->childFromChar(c) == nullptr) {
				current->setChildFromChar(c, new Node);
			}
			current = current->childFromChar(c);
		}
		current->addWord(w);
	}
}

const vector<string>& matchingWords(long int digits) {
	//setup strokes
	vector<char> digs;
	vector<string> empty;
	while (digits>0) {
		char d = digits % 10;
		if (2 <= d && d <= 9) digs.push_back(d);
		else {
			cout << "Invalid digit (" << d << ")" << endl;
			return empty;
		}

		digits /= 10;
	}

	//search tree
	Node* current = &root;
	for (int i = digs.size() - 1; i >= 0; i--) {
		if (current->childFromDigit(digs[i]) == nullptr) {
			cout << "Word not found" << endl;
			return empty;
		}
		current = current->childFromDigit(digs[i]);
	}
	return current->words();
}

const vector<string> readFile(const string& filename) {
	vector<string> res;
	ifstream myfile(filename);
	string line;
	while (getline(myfile, line)) res.push_back(line);
	return res;
}


int main() {
	for (auto s : dial) cout << "\t" << s << endl;

	cout << endl << "Processing... ";
	setupIndices();
	vector<string> wordsFile = readFile("../0_data/english_words_1000.txt");
	processWords(wordsFile);
	cout << "done." << endl << endl;



	while (true) {
		cout << "Please insert digits sequence for T9: " << endl;
		long int d; cin >> d;
		cout << "Matching words are " << endl;
		for (auto w : matchingWords(d)) cout << w; cout << endl;
	}

	return 0;
}