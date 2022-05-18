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

vector<int> twoSum1(vector<int> &nums, int target)
{
    // sort(nums.begin(),nums.end());
    vector<int> v;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] > target)
        {
            cout << "nums[i]+nums[j] > target" << endl;
            j--;
        }
        else if (nums[i] + nums[j] < target)
        {
            cout << "nums[i]+nums[j] < target" << endl;
            i++;
        }
        else
        {
            cout << "nums[i]+nums[j] = target" << endl;
            v.push_back(i);
            v.push_back(j);
            return v;
        }
    }
    return v;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = i;
    }
    for(int i = 0; i<nums.size();i++)
    {
        auto it = m.find(target-nums[i]);
        if((it!=m.end())&&(it->second!=i))
        {
            return {it->second, i};
        }     
    }
    return {};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, t;
        cin >> n >> t;
        vector<int> v, out;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }

        out = twoSum(v, t);
        cout << "twoSum(v, t):";
        printVector(out);
    }
}