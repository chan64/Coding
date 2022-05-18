#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    bitset<32> bset(n);
    // cout<<bset<<endl;
    return bset.count();
}

int hammingWeight1(uint32_t n) {
    int c = 0;
    while(n){
        // cout<<bitset<32> (n)<<" - "<<bitset<32> (n&1)<<endl;
        if((n&1)==1)
        {
            c++;
        }
        n = n>>1;
    }
    return c;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin>>n;
        int out = hammingWeight1(n);
        printf("hammingWeight(%d) = %d\n", n, out);

    }
    return 0;
}