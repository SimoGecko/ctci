#include <iostream>
#include <string>

using namespace std;

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

bool isUnique(string s)
{
    return false;
}

int main()
{
    string s = "probably";
    SortString(s, 0, s.length() - 1);
    cout << s << endl;


    return 0;
}