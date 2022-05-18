#include <iostream>
#include <string.h>

using namespace std;
string longPalindrome(string s);
bool checkPalindrome(string str);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << longPalindrome(s) << endl;
    }
    return 0;
}
bool checkPalindrome(string str)
{
    int i = 0, j = str.length() - 1;
    while (i < j)
    {
        // cout<<str[i]<<" "<<str[j]<<endl;
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
string longPalindrome(string s)
{
    int n = s.length();
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                // cout << s.substr(i, j - i + 1) << " (" << i << "," << j << ")" << endl;
                if (checkPalindrome(s.substr(i, j - i + 1)))
                {
                    arr[i][j] = j - i;
                }
            }
        }
    }
    int max = 0, maxi = 0, maxj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
                maxi = i;
                maxj = j;
            }
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    return s.substr(maxi,maxj-maxi+1);
}
