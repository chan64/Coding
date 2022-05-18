#include <iostream>
using namespace std;

void subarray_sum(int a[], int n, int s)
{
    int i = 0, j = 0, sum = a[0];
    while (sum != s && ((i != n) && (j != n)))
    {
        // cout<<sum<<" "<<i<<" "<<" "<<j<<endl;
        if (sum > s && i < n)
        {
            sum -= a[i];
            i++;
        }
        if (sum < s && j < n)
        {
            j++;
            sum += a[j];
        }
    }
    if (sum == s)
    {
        cout << i+1<< " " << j+1<< " "<<sum << " "<< s << endl;
    }
    else
    {
        cout << -1 << " " << -1 << " "<< sum << " "<< s <<endl;
    }
    return;
}

int main()
{
    //code
    int t;
    // cout << "Enter t:";
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        // cout << "Entered values:" << n << " "<<s <<endl;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            // cout << "Enter a[i]:";
            cin >> a[i];
        }
        subarray_sum(a, n, s);
        // while(sum == s)
        // {
        //     sum += a[i]
        // }
        // cout<<i<<" "<<j<<endl;
    }
    return 0;
}
