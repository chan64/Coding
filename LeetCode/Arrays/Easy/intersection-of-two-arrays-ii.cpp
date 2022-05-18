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


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector <int> v;
    unordered_map<int,int> m;
    for(int a:nums1)
    {
        m[a]++;
    }
    for(int i = 0;i<nums2.size();i++)
    {
        if(m.find(nums2[i])!=m.end()&& m[nums2[i]]!=0)
        {
            v.push_back(nums2[i]);
            m[nums2[i]]--;
        }
    }
    return v;
}

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    vector<int> result = intersect(nums1, nums2);
    cout<<"After intersect():"<<endl;
    print_vector(result);

    return 0;
}