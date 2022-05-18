#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void rotate(vector<vector<int> >& v) {
    int n = v.size();
    for(int i = 0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j>i)
            {
                swap(v[i][j], v[j][i]);
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        int first = 0, last = n-1;
        while(first<last)
        {
            swap(v[i][first], v[i][last]);
            first++;
            last--;
        }
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             // printf("(%d,%d) ",i,j);
    //             cout << v[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        cout<<"Before Swap"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // printf("(%d,%d) ",i,j);
                cout << v[i][j]<<" ";
            }
            cout<<endl;
        }

        rotate(v);

        cout<<"After Swap"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // printf("(%d,%d) ",i,j);
                cout << v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}