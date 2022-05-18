// { Driver Code Starts
#include<iostream>
#include<string.h>

using namespace std;

int reverseInt(int x) {
    int d = 0, n = 0, rev = 0;
    if(x>INT_MAX|| x<INT_MIN)
        return 0
    while(x)
    {
        d = x%10;
        x = x/10;
        rev = rev*10+ d;
    }
    return rev;
}

int reverseInt1(int x) {
    int d = 0, n = 0, rev = 0;
    while(x)
    {
        d = x%10;
        x = x/10;
        rev = rev*10+ d;
    }
    return rev;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int s;
        cin >> s;
        cout<<reverseInt(s)<<endl;
    }
}// } Driver Code Ends
