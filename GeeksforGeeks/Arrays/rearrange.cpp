#include <iostream>
using namespace std;

class Solution
{
public:
    void rearrange(long long *arr, int n)
    {
        int min_i = 0, max_i = n-1, max = arr[max_i]+1;
        for(int i = 0;i<n;i++)
        {
            if(i%2==0){
                arr[i]+=(arr[max_i]%max)*max;
                max_i--;
            }
            else
            {
                arr[i]+=(arr[min_i]%max)*max;
                min_i++;    
            }
        }
        for(int i = 0;i<n;i++)
        {
            arr[i] = arr[i]/max;
        }
    }
    void rearrange2(long long *arr, int n)
    {
        int i = 0, j, max;
        while(i<n)
        {
            j = n-1;
            max = arr[j];
            while(j>i)
            {
                arr[j]=arr[j-1];
                j--;
            }
            arr[i] = max;
            i = i+2;
        }
    }
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange1(long long *arr, int n)
    {
        int i = 1, j = 0;
    	long long arr1[n];
        if(n==0||n==1)
    	    return;
    	while(i<n&&j<n)
    	{
            // printf("%d %d",arr1[i])
    	    arr1[i] = arr[j];
    	    i = i+2;
    	    j++;
    	}
        // cout<<i<<" "<<j<<" "<<n<<endl;
        if(n%2==0)
        {
            i = n-2;
        }
        else
            i = n-1;
    	while(i>=0&&j<n)
    	{
    	    arr1[i] = arr[j];
    	    i = i-2;
    	    j++;
    	}
    	for(int i = 0;i<n;i++)
    	{
    	    arr[i] = arr1[i];
    	}
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        ob.rearrange(arr, n);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
