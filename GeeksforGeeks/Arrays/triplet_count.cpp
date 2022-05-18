#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//User function template for C++
class Solution
{
public:
    int countTriplet(int arr[], int n)
    {
        int table[n][n];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cout << i << "," << j << endl;
                table[i][j] = arr[i] + arr[j];
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (table[i][j] == arr[k])
                    {
                        count++;
                    }
                }
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        return count;
    }

    int calculateSize(int n)
    {
        return (n*n - n)/2;
    }
    int countTriplet1(int arr[], int n)
    {
        int c = 0, j,k;
        sort(arr, arr+n);
        for(int i = 0;i<n-2;i++)
        {
            j = i+1;
            k = i+1;
            while(k<n)
            {
                if(arr[i]+arr[j]==arr[k])
                {
                    c++;
                }
                else if(arr[i]+arr[j]<arr[k])
                {
                    j++;
                    k--;
                }
                k++;
            }
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet1(arr, n) << "\n";
    }
    return 0;
}