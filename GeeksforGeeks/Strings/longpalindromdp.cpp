#include <iostream>
#include <string.h>

using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    bool table[n][n];
    memset(table, 0, sizeof(table));

    int maxl = 1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        start = i;
        table[i][i] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxl = 2;
        }
    }

    for (int k = 3; k < n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] && table[i + 1][j - 1] == true)
            {
                table[i][j] = true;
                if (k > maxl)
                {
                    start = i;
                    maxl = k;
                }
            }
        }
    }
    return s.substr(start, maxl);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}

