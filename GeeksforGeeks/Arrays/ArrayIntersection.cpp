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

vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v, v1, v2;
    v1 = nums1.size() >= nums2.size()? nums1 : nums2;
    v2 = nums1.size() < nums2.size()? nums1 : nums2;
    // printVector(v1);
    // printVector(v2);
    cout<<v1.size()<<" "<<v2.size()<<endl;
    for(int i = 0;i<v2.size();i++)
    {
        for(int j = 0;j<v1.size();j++)
        {
            printf("v1[%d]=%d v2[%d]=%d\n", i, v1[i], j, v2[j]);
            if(v1[j]==v2[i])
            {
                v.push_back(v2[i]);
                v2[i] = -1;
            }
        }
    }
    return v;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    unordered_map<int, int> m;
    for(int i: nums1) { m[i]++;} 
    for(int i: nums2) 
    { 
        if(m.find(i)!=m.end()&& --m[i] >= 0)
        {
            v.push_back(m.find(i)->first);
        }
    } 
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, num;
        cin >> n1 >> n2;
        vector<int> v1, v2, out;
        for (int i = 0; i < n1; i++)
        {
            cin >> num;
            v1.push_back(num);
        }

        for (int i = 0; i < n2; i++)
        {
            cin >> num;
            v2.push_back(num);
        }
        // printVector(v1);
        // printVector(v2);
        out = intersect(v1, v2);
        cout<<"intersect(v1, v2): "<<endl;
        printVector(out);

    }
}