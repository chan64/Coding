#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout <<v[i]<< " ";
    }
    cout << endl;
}

vector<int> buildArray(vector<int>& nums) {
    vector<int> out(nums.size(),0);
    for(int i = 0;i<nums.size();i++)
    {
        // printf("out[%d]=%d nums[%d]=%d\n",i,out[i],i,nums[i]);
        out[i]=nums[nums[i]];
    }
    return out;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

vector<int> build_array_in_place(vector<int>& nums) {
    int q = nums.size(), r = 0, b = 0;

    for(int i = 0;i<nums.size();i++)
    {
        r = nums[i];
        b = nums[nums[i]]%q;
        nums[i]=q*b+r;
    }
    for(int i = 0;i<nums.size();i++)
    {
        nums[i] = nums[i]/q;
    }
    return nums;
}

int main(){
    vector<int> nums = {0,2,1,5,3,4}, out = {};
    out = buildArray(nums);
    print_vector(out);
}