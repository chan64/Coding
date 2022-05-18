#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> v;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            v.push_back("FizzBuzz");
        else if (i % 3 == 0)
            v.push_back("Fizz");
        else if (i % 5 == 0)
            v.push_back("Buzz");
        else
            v.push_back(to_string(i));
    }
    return v;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // for(int i = 0;i<n;i++)
    return nums[0];
}

int missingNumber1(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    // for(int num:nums){
    //     n^=num;
    //     n^=i;
    //     i++;
    // }
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
        // vector<string> v;
        vector<int> v;
        // v = fizzBuzz(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        cout<<"Missing Number:"<<missingNumber1(v)<<endl;
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        cout << endl;
        // printf("isPowerOfThree(%d): %s \n", n, isPowerOfThree1(n)?"true":"false");
    }
    return 0;
}