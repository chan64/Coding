#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout <<v[i]<< " ";
    }
    cout << endl;
}

vector<int> getConcatenation1(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(2*n);
    if(n==0)
        return result;
    // printf("nums size=%d, result size=%d\n", n,result.size());
    for(int i = 0;i<n;i++)
    {
        result[i] = result[i+n] = nums[i];
    }
    return result;
}

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    if(n==0)
        return nums;
    for(int i = 0;i<n;i++)
    {
        nums.push_back(nums[i]);
    }
    return nums;
}

int main(){
    vector<int> nums = {1,2,3}, out = {};
    out = getConcatenation(nums);
    print_vector(out);
}