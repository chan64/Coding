#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s)
{
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        auto it = m.find(s[i]);
        if(it==m.end())
        {
            continue;
        }
        else
        {
            if(it->second==1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int out = firstUniqChar(s);
        printf("firstUniqChar(%s):%d\n", s.c_str(), out);
    }
}