#include <bits/stdc++.h>
using namespace std;

string removeNonAlphanumberic(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    printf("%d,%d,%d,%d,%d,%d\n", 'A', 'Z', 'a', 'z', '0', '9');
    for (int i = 0; i < s.size(); i++)
    {
        printf("s[%d]=%c=%d\n", i, s[i], s[i]);
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9'))
        {
            s.erase(i, 1);
            i--;
        }
    }
    return s;
}

bool isPalindrome(string s)
{
    s = removeNonAlphanumberic(s);
    int n = s.size();
    cout << "s= " << s << endl;
    if (n == 0 || n == 1)
        return true;
    for (int i = 0, j = n - 1; i < n - 1 && j > 0; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    int t;
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin, s, '\n');
        string out = isPalindrome(s) ? "true" : "false";
        cout << "isPalindrome(): " << out << endl;
    }
}