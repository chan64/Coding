#include <bits/stdc++.h>
using namespace std;

int minPartitions1(string n) {
    sort(n.begin(), n.end());
    // cout<<n<<" "<<endl;
    return n[n.size()-1] - '0';
}

int minPartitions(string n) {
    int res = 0;
    for(int i = 0;i<n.size();i++)
    {
        res = max(res, n[i]-'0');
    }
    return res;
}

int main()
{
    string n = "82734";
    int out = minPartitions(n);
    cout<<"minPartitions("<<n<<"):"<<out<<endl;
}