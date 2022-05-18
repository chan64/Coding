#include <iostream>
#include <set>
#include <vector>
using namespace std;


int fact(int n)
{
    if(n==1||n==0)
        return 1;
    return n*fact(n-1);
}
set<string> permute(string s, int n, set<string> s1)
{
    // cout<<ss.size()<<" "<<fact(n)<<endl;
    if(s1.find(s)==s1.end())
    {
        s1.insert(s);
    }
    else
        return s1;
    for(int i = 0;i<n;i++)
    {
        swap(s[i],s[(i+1)%n]);
        s1 = permute(s,n,s1);
    }
    return s1;
}


void permutations(string s)
{
    set <string> ss;
    int n = s.length();
    ss = permute(s, n, ss);
    // cout<<ss.size()<<endl;
    // cout << "\nAll elements : "; 
    set<string> :: iterator itr; 
    for (itr = ss.begin(); itr != ss.end(); itr++) 
        cout << (*itr) << " "; 
    cout<<endl;
}

int main() {
	string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        permutations(s);
    }
	return 0;
}