#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>

using namespace std;

string double2string(double d)
{
    stringstream ss;
    ss << "0.";
    double x = 1;
    for(int i=0; i<30; i++){
        x/=2;
        if(d>=x){
            ss << "1";
            d-=x;   
        }else{
            ss << "0";
        }
    }
    
    if(d!=0) return "ERROR";
    return ss.str();
}


int main()
{
    double d = 0.8125;//0.72;
    cout << double2string(d) << endl;

    return 0;
}