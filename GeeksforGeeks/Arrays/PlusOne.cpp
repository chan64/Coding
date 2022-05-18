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

vector<int> plusOne1(vector<int>& digits) {
    vector<int> v;
    int num = 0;
    int n = digits.size();
    for(int i = n-1;i>=0;i--)
    {
        // cout<<i<<" "<<(n-i-1)<<endl;
        cout<<num<<endl;
        num+=(digits[i]*(pow(10,n-i-1)));
    }
    num++;
    cout<<num<<endl;
    while(num)
    {
        int d = num%10;
        v.insert(v.begin(), d);
        num = num/10;
    }
    // printVector(v);
    return v;
}

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size()-1;
    while(i>=0)
    {
        if(digits[i]<9)
        {
            digits[i]++;
            return digits;
        }
        else
        {
            digits[i] = 0;
            i--;
        }
    }
    if(digits[0]==0&&digits.size()>0)
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;
        vector<int> v, out;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }

        out = plusOne(v);
        cout << "plusOne(v):";
        printVector(out);
    }
}