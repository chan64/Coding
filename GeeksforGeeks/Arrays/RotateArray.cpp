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

void rotateOnce(vector<int> &v)
{
    int ext = v[0];
    int n = v.size();
    for (int i = n-1; i >= 0; i--)
    {
        cout<<v[(i + 1) % n]<<" "<<v[i]<<endl;
        v[(i + 1) % n] = v[i];
    }
    v[1] = ext;
}

void rotate1(vector<int> &v, int k)
{
    if(v.size()==0||v.size()==1)
    {
        return;
    }
    while(k--)
    {
        rotateOnce(v);
    }
    return;
}

void reverse(vector<int> &v, int start, int end)
{
    while(start<end)
    {
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }
}

void rotate(vector<int> &v, int k)
{
    int n = v.size();
    if(n==0||n==1)
    {
        return;
    }
    reverse(v,0,n-1);
    // printVector(v);

    reverse(v,0,k-1);
    // printVector(v);

    reverse(v,k, n-1);
    // printVector(v);
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        cout << "Before Rotate :";
        printVector(v);

        rotate(v, k);

        cout << "After Rotate  :";
        printVector(v);
    }
}