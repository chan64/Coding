#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

bool isPowerOfThree(int n) {
    float a = log(n)/log(3);
    printf("log(%d)=%f log(%d)/log(3)=%f, fmod=%f\n",n, log(n), n, a, fmod(a,1));
    return fmod(a,1) == 0;
}

bool isPowerOfThree1(int n) {
    if(n<1)
            return false;
    while(n%3==0)
    {
        n/=3;
    }
    return n==1;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        // printf("isPowerOfThree(%d): %s \n", n, isPowerOfThree1(n)?"true":"false");
    }
    return 0;
}