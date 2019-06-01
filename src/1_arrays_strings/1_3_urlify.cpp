#include <iostream>
#include <string>

using namespace std;

//swap spaces to %20
string Urlify(string& s){

    //count spaces
    int spaces = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s.at(i)==' ') spaces++;
    }
    
    //setup string
    char* c = new char[s.length() + spaces*2];

    //go though, copy
    int j=0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s.at(i)==' '){
            c[j++] = '%';
            c[j++] = '2';
            c[j++] = '0';
        }else{
            c[j++]=s.at(i);
        }
    }
    return string(c);
}


int WinMain()
{
    string s = "Mr John Smith";
    cout << Urlify(s) << endl;

    return 0;
}