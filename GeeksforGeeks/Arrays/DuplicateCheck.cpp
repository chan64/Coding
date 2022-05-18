#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool containsDuplicate(vector<int>& nums) {
    map<int,bool> m;
    for(int i: nums)
    {
        if (m.find(i) != m.end())
            return true;
        else
            m[i] = true;
        // if(m[i]>=1)
        //     return true;
        // m[i]++;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, k;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        printVector(v);
        string s = containsDuplicate(v)? "true": "false";
        cout<<"containsDuplicate(): "<<s<<endl;

    }
}