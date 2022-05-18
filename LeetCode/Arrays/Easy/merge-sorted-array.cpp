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

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        printf("nums1[%d]=%d nums2[%d]=%d k=%d\n", i, nums1[i], j, nums2[j], k);
        if (nums1[i] >= nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
    return;
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int n = nums2.size();
    int m = nums1.size() - n;

    merge(nums1, m, nums2, n);
    cout<<"After merge():"<<endl;
    print_vector(nums1);
    print_vector(nums2);

    return 0;
}