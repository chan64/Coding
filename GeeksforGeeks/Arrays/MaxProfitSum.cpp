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

void print2DVector(vector<vector<int> > &v_2D)
{
    for (int i = 0; i < v_2D.size(); i++)
    {
        for (int j = 0; j < v_2D[i].size(); j++)
        {
            cout << v_2D[i][j] << " ";
        }
        cout << endl;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

int maxProfit(vector<int> &a)
{
    int n = a.size()-1;
    if(n<1)
        return 0;
    int i = 0, valley = 0, peak = 0, maxprofit = 0;
    while(i<n)
    {
        while(i<n&&a[i]>=a[i+1])
        {
            i++;
        }
        valley = a[i];
        while(i<n&&a[i]<=a[i+1])
        {
            i++;
        }
        peak = a[i];
        cout<<peak<<" "<<valley<<endl;
        maxprofit+= peak-valley;
        i++;
    }
    return maxprofit;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, out;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }

        // cout << endl;
        out = maxProfit(v);
        cout << "maxProfit(v): " << out;
        // printVector(v);
    }
}