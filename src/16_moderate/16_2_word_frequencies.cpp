#include <iostream>
#include <map>

#include <fstream>

using namespace std;


map<string, int> dic;

void processText(){
	string fileName = "dante.txt";

	ifstream f = fopen(fileName);
	string word;
	while(f>>word){
		//normalize
	}

}

void find(string word){

}

int main(){
	processText();

	string in;
	while(true) {
		cout << "Enter string to search: " << endl;
		cin >> in;
		if(!in) break;

		find(in);
	}

	return 0;
}