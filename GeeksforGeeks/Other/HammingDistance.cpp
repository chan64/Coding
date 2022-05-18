#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int z = x^y, dist = 0;
    while(z){
        ++dist;
        z&=z-1;
    }
    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin>>x>>y;
        int out = hammingDistance(x,y);
        cout<<"x="<<bitset<32> (x)<<"\ny="<<bitset<32> (y)<<endl;
        printf("hammingDistance(%d, %d) = %d\n", x, y, out);
        cout<<bitset<32> (out)<<endl;
    }
    return 0;
}