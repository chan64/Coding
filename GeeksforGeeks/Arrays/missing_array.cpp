#include <iostream>
#include <vector>
using namespace std;

// User function template for C++

int MissingNumber(vector<int>& array, int n) {
    sort(array.begin(), array.end());
    for(int i = 0;i<n-1;i++)
    {
        cout<<i+1<<" "<<array[i]<<endl;
        if(i+1!=array[i])
        {
            return i+1;
        }
    }
    return n;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n-1);
        for (int i = 0; i < n-1; ++i)
        {
            cin >> array[i];
        }
        cout<<MissingNumber(array, n)<<endl;
    }
    return 0;
}