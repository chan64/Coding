#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int result = 0;
    for(string s:operations){
        if((s[1]=='+'))
            result++;
        if((s[1]=='-'))
            result--;
        // cout<<s<<" "<<s[0]<<" "<<s[s.length()-1]<<" "<<result<<endl;
    }
    return result;
}

void print_vector(vector<string> vs){
    for(string s:vs)
        cout<<s<<" ";
    cout<<endl;
}

int main()
{
    vector<string> op={"--X","X++","X++"};
    cout<<finalValueAfterOperations(op);
    // print_vector(op);
}