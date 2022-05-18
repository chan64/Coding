#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int reverse(int x) {
    int q = x/10, r = 0, rev = 0;
    while(x)
    {
        r = x%10;
        if(rev>(INT_MAX/10)|| rev<(INT_MIN/10))
            return 0;
        rev = rev * 10 + r;
        x = x/10;
    }
    return rev;
}

int main()
{
    int num = -123, out;
    out = reverse(num);
    cout<<"reverse():"<<out<<endl;
    // cout<<INT_MIN<<" "<<INT_MAX<<endl;
}