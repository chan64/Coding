// { Driver Code Starts
#include<iostream>
#include<string.h>

using namespace std;
string reverseWords(string s);
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string S) 
{ 
    int j = S.length(), i = S.length();
    string reverse = "";
    while(i--)
    {
        if(S[i]=='.')
        {
            // cout<<i<<" "<<j<<endl;
            reverse+=S.substr(i+1,j-i-1)+'.';
            j = i;
        }
    }
    // cout<<i<<" "<<j<<endl;
    reverse+=S.substr(0,j);
    return reverse;
} 