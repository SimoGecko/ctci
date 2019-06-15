// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>

using namespace std;

//swap spaces to %20
string urlify(const string& str) {
    //count spaces
    int spaces = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') spaces++;
    }

    //corner cases
    if (spaces == 0) return str;

    //setup string
    string s(str);
    s.append(spaces * 2, ' '); // add required space

                               //go though, copy
    size_t j = s.size() - 1;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (i == j) break;

        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
        else {
            s[j--] = s[i];
        }
    }

    return move(s);
}


int main() {
    cout << "Swaps spaces with %20. " << endl << endl;
    while (true) {
        cout << "Insert string s: " << endl;
        string s; //cin >> s;
        getline(cin, s);
        //s = "Mr John Smith";
        cout << "urlify = " << urlify(s) << endl << endl;
    }
    return 0;
}