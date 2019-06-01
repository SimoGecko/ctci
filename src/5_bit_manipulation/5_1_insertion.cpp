#include <iostream>
#include <assert.h>
using namespace std;

int insert(int N, int M, short i, short j)
{
    short x = j-i+1;
    int mask = (1<<x)-1;
    N = N & (~(mask<<i));
    N = N | ((M&mask)<<i);
    return N;
}


int main()
{

    int N = 1024; // 10000000000
    int M = 19;   // 10011
    int R = 1100; // 10001001100
    int O = insert(N, M, 2, 6);
    assert (R==O);

    return 0;
}