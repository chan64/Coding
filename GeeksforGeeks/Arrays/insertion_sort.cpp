#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for(int i = 0;i<n;i++)
    {
        int key = a[i], j = i;
        while(j>0&&key<=a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        a[j]= key;
    }
    for (int i = 0; i < n; i++)
        {
            // cout << "Enter a[i]:";
            cout<< a[i]<<" ";
        }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n;
        // cout << "Entered values:" << n << " "<<s <<endl;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            // cout << "Enter a[i]:";
            cin >> a[i];
        }
        insertion_sort(a, n);
    }
    return 0;
}
