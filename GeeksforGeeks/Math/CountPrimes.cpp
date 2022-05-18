#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i = 2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int countPrimes(int n)
{
    int c = 0;
    for(int i = 2;i<n;i++)
    {
        // cout<<i<<" "<<isPrime(i)<<endl;
        if(isPrime(i))
            c++;
    }
    return c;
}

int countPrimes1(int n)
{
    int arr[n], c = 0;
    arr[0] = -1;
    arr[1] = -1;
    for(int i = 2;i<n;i++)
    {
        arr[i] = i;
    }
    // for(int i = 0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl;
    for(int i = 2;i<n;i++)
    {
        if(arr[i]==-1)
            continue;
        int s = arr[i];
        int j = 2;
        while((j*s)<n)
        {
            // printf("i=%d s=%d j=%d arr[j*s]=%d n=%d\n", i, s,j,arr[j*s], n);
            arr[j*s] = -1;
            j = j+1;
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(arr[i]!=-1)
        {
            c++;
            // cout<<arr[i]<<" ";
        }  
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res;
        cin >> n;
        res = countPrimes1(n);
        cout << "countPrimes(" << n << ") : " << res << endl;
    }
    return 0;
}