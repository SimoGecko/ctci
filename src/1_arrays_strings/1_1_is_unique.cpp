// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>

using namespace std;


//using additional DS (space)
// O(100) space
// O(n) time
const char minAscii = ' '; // 32
const char maxAscii = '~'; // 126
//assume allowed chars are a-z A-Z 0-9

bool isUnique(const string& s){
    bool seen[maxAscii-minAscii+1];
    for(size_t i=minAscii; i<=maxAscii; ++i) seen[i-minAscii]=false;

    for(size_t i=0; i<s.size(); ++i){
        if(seen[s[i]-minAscii]) return false;
        seen[s[i]-minAscii] = true;
    }
    return true;
}


//without using any additional space
// O(1) space
// O(n logn) time



//TODO finish
void swapChars(string &s, int a, int b)
{
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

void SortString(string& s, int l, int r)
{
    if (l >= r) return;

    int p = r;
    int i=l;
    int j=r-1;

    while (i < j)
    {
        while (s[i] <  s[p] && i < r - 1) i++;
        while (s[j] >= s[p] && j > l)     j--;
        if (i < j)
        {
            swapChars(s, i++, j--);
        }
    }
    swapChars(s, i, p);

    SortString(s, l, i - 1);
    SortString(s, i, r);
}





//--------------

int main()
{
    cout << "Computes if a string has all unique characters. " << endl << endl;
    while(true){
        cout << "Insert string s: " << endl;
        string s; cin >> s;
        cout << "all unique characters: " << (isUnique(s)? "yes" : "no") << endl << endl;
    }   
    return 0;
}