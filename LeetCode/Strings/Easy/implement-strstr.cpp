#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int m = haystack.size();
    int n = needle.size();
    if(n==0)
        return 0;
    for (int i = 0; i <= m - n; i++)
    {
        int j = 0;
        // cout<<"In i loop"<<endl;
        for (; j < n; j++)
        {
            // cout<<"In j loop"<<endl;
            if (haystack[i + j] != needle[j]){
                break;
                // cout<<"In if cond"<<endl;
                // printf("%d, %d", j,n);
            }
        }
        // cout<<"Out here"<<endl;
        // printf("%d, %d", j,n);
        if (j == n)
        {
            // cout<<"In j==n cond"<<endl;
            return i;
        }
            
    }
    return -1;
}

int main()
{
    string haystack = "a", needle = "";
    printf("Finding %s (needle) in %s (haystack)\n", needle.c_str(), haystack.c_str());
    cout << "index="<<strStr(haystack, needle);
    // print_vector(op);
}