#include <bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    string result=s;
    for(int i = 0;i<s.size();i++)
    {   
        result[indices[i]] = s[i];
    }
    return result; 
}

int main()
{
    string s = "codeleet", out;
    vector<int> indices = {4,5,6,7,0,2,1,3};
    out = restoreString(s,indices);
    cout<<"restoreString():"<<out<<endl;
}