#include <bits/stdc++.h>
using namespace std;

void print2DVector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> numtoVector(int n)
{
    vector<int> v_inn = {};
    while (n)
    {
        int d = n % 10;
        n = n / 10;
        v_inn.push_back(d);
    }
    return v_inn;
}

vector<vector<int>> generate1(int numRows)
{
    vector<vector<int>> v;
    for (int i = 0; i < numRows; i++)
    {
        v.push_back(numtoVector(pow(11, i)));
    }
    return v;
}

vector<vector<int>> generate2(int numRows)
{
    vector<vector<int>> v(numRows, vector<int>(numRows, 0));
    vector<vector<int>> v_out;
    cout << numRows << endl;
    v[0][0] = 1;
    for (int i = 0; i < numRows; i++)
    {
        v[i][0] = 1;
        v[0][i] = 1;
    }

    // for (int i = 1; i < numRows; i++)
    // {
    //     for (int j = 1; j < numRows; j++)
    //     {
    //         if(v[i][j]==0&&(i+j)<numRows)
    //         {
    //             v[i][j] = v[i-1][j] + v[i][j-1];
    //         }
    //     }
    // }
    for (int c = 0; c < numRows; c++)
    {

        int i = c, j = 0;
        vector<int> v_inner = {};
        v_inner[i] = v_inner[j] = 1;
        while (i >= 0 && (i + j) == c)
        {
            if (v[i][j] == 0 && (i + j) < numRows)
            {
                v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
            v_inner.push_back(v[i][j]);
            // printf("(%d+%d)=%d ", i, j, v[i][j]);
            i--;
            j++;
        }
        v_out.push_back(v_inner);
        v_inner.clear();
        // cout<<endl;
    }
    // cout<<"--------"<<endl;

    // for (int i = 0; i < v_out.size(); i++)
    // {
    //     for (int j = 0; j < v_out[i].size(); j++)
    //     {
    //         printf("(%d,%d)=%d ", i, j, v_out[i][j]);
    //         // cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return v_out;
}

vector<vector<int>> generate(int n)
{
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> v_inn(i + 1, 1);
        // print2DVector(v);
        for (int j = 1; j < i; j++)
        {
            printf("v_inn[%d] = v[%d][%d] + v[%d][%d]\n", j, i - 1, j - 1, i - 1, j);
            printf("%d = %d + %d \n", v_inn[j], v[i - 1][j - 1], v[i - 1][j]);
            v_inn[j] = v[i - 1][j - 1] + v[i - 1][j];
        }
        v.push_back(v_inn);
    }
    return v;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v = generate(n);
        printf("generate(%d)\n", n);
        print2DVector(v);
    }
    return 0;
}