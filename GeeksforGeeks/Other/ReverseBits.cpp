#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBit(uint32_t n)
{
    int rev = 0, i = 1;
    while(n&&i<=32)
    {
        int lsb = n&1;
        // printf("lsb=%d i=%d\n", lsb, i);
        // cout<<"lsb= "<<lsb<<endl;
        rev|=lsb<<(32-i);
        n = n >>1;
        i++;
    }
    // cout<<endl;
    return rev;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin>>n;
        int out = reverseBit(n);
        cout<<"n = "<<bitset<32> (n)<<"\nout="<<bitset<32> (out)<<endl;
        printf("reverseBit(%d) = %d\n", n, out);

    }
    return 0;
}