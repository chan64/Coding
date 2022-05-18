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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void moveZeroes(vector<int>& v) {
    int i = 0, j = 0, n = v.size()-1;
    while(i<n)
    {
        if(v[i]==0)
        {
            j = i;
            while(v[j]==0&&j<n)
                j++;
            swap(v[i], v[j]);
            printVector(v);
        }
        i++;
    }   
    return; 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }

        moveZeroes(v);
        cout << "moveZeroes(v):";
        printVector(v);
    }
}