#include <bits/stdc++.h>
using namespace std;

void print_2Dvector(vector<vector<int>> &mat)
{
    for (vector<int> a : mat)
    {
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> getRow1(int rowIndex)
{
    int n = rowIndex;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    // print_2Dvector(v);
    return v[rowIndex];
}

vector<int> getRow(int rowIndex)
{
    int n = rowIndex;
    vector<int> v(n + 1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            v[j] = v[j - 1] + v[j];
        }
    }
    // print_2Dvector(v);
    return v;
}

int main()
{
    int rowIndex = 5;
    vector<int> out;

    out = getRow(rowIndex);
    printf("getRow(%d)=", rowIndex);
    print_vector(out);
    return 0;
}