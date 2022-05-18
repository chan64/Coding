#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool isAnagram1(string s, string t)
{
    int arr[256]={0}, ns=s.size(),ts=t.size();
    if(ns!=ts)
        return false;
    for(int i = 0;i<ns;i++)
    {
        arr[s[i]]++;
    }
    for(int i = 0;i<ts;i++)
    {
        if(arr[t[i]])
            arr[t[i]]--;
        else   
            return false;
        // a_sa[s[i]]++;
    }
    return true;
}

bool isAnagram(string s, string t)
{
    int ns=s.size(),ts=t.size();
    unordered_map<int,char> m;
    if(ns!=ts)
        return false;
    for(int i = 0;i<ns;i++)
    {
        m[s[i]]++;
    }
    for(int i = 0;i<ts;i++)
    {
        if(m.find(t[i])==m.end())
            return false;
        else   
            m[t[i]]--;
        // a_sa[s[i]]++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        string out = isAnagram(s, t) ? "true" : "false";
        printf("isAnagram(%s,%s):%s\n", s.c_str(), t.c_str(), out.c_str());
    }
}