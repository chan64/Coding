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

int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    if(nums.size()==1)
    {
        return nums[0];
    }
    for(int i = 0; i<nums.size(); i = i+2)
    {
        if(nums[i]!=nums[i+1])
        {
            return nums[i];
        }
    }
    // printVector(nums);
    return -1;
}

int singleNumberXOR(vector<int>& nums) {
    int result = nums[0];
    for(int i = 1; i<nums.size(); i++)
    {
        result^= nums[i];
    }
    // printVector(nums);
    return result;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, k;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        printVector(v);
        int out = singleNumberXOR(v);
        cout<<"singleNumberXOR(): "<<out<<endl;

    }
}