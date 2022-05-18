#include <iostream>
using namespace std;

class Solution{
  public:
    bool isRotated(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        int i = 0, j = m-2, k = 2;
        if(m!=n)
        {
            return false;
        }
        if(n==0)
        {
            return true;
        }
        if(n==1)
        {
            // cout<<n<<endl;
            if(str1==str2)
                return true;
            else
                return false;
        }
        while(i<n)
        {
            if(str1[i]!=str2[j]&&str1[i]!=str2[k])
                return false;
            // printf("%d , %d , %d \n", i,j,k);
            i = i+1;
            j = (j+1)%m;
            k = (k+1)%m;
        }
        return true;
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string b;
        cin>>s>>b;
        Solution obj;
        cout<<obj.isRotated(s,b)<<endl;
    }
}
