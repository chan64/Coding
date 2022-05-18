#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int n = s.size(), num = 0;
    map<string, int> m = {{"I", 1},{"IV", 4},{"V", 5},{"IX", 9},{"X", 10},{"XL", 40},{"L", 50},{"XC", 90},{"C", 100},{"CD", 400},{"D", 500},{"CM", 900},{"M", 1000}};
    map<string,int>::iterator it;
    // for(it = m.begin();it!=m.end();it++)
    // {
    //     cout<<it->first<<"->"<<it->second<<endl;
    // };
    int i = 0;
    while(i<n)
    {
        string s2 = s.substr(i,2);
        // cout<<"2:"<<s2<<" ";
        it = m.find(s2);
        if(it==m.end())
        {
            // cout<<"1:"<<s.substr(i,1)<<" ";
            it = m.find(s.substr(i,1));
            if(it==m.end())
            {
                return -1;
            }
            else{
                num+=it->second;
                i++;
            }
        }
        else
        {
            num+=it->second;
            i = i+2;
        }
        // cout<<endl;
    };
    return num;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        // cin >> n;
        // vector<string> v;
        cin >> str;
        // cout << str;
        n = romanToInt(str);
        cout<<"romantoInt("<<str<<") : "<<n<<endl;
    }
    return 0;
}