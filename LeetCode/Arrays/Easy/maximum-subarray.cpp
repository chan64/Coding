#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int maxSubArray(vector<int> &nums)
{
    int max_global = INT_MIN, max_current = 0;
    max_global = max_current = nums[0];
    for(int i = 1;i<nums.size();i++)
    {
        max_current = max(nums[i], max_current + nums[i]);
        max_global = max(max_current, max_global);
        // max_current = max(max_current,0);
    }
    return max_global;
}

int main()
{
    vector<int> nums = {5,4,-1,7,8};
    int out;
    out = maxSubArray(nums);
    cout<<"maxSubArray():"<<out<<endl;
    // cout<<INT_MIN<<" "<<INT_MAX<<endl;
}