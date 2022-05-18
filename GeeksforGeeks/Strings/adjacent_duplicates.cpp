#include <iostream>
using namespace std;

bool check_duplicates(string s)
{
    string out;
    int i = 0, j = i+1, k = 0, l = 0, n = s.length();
    while(k<n)
    {
        // cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
        if(s[k]==s[j])
        {
            l++;
            j++;
        }
        else if(s[k]!=s[j])
        {
            if(l==0)
            {
                j++;
                k++;
            }
            else if(l!=0)
            {
                return true;
                out += s.substr(i,k-i);
                j++;
                i = j - 1;
                k = i;
                l = 0;
            }
        }
    }
    return false;
}

string adj_duplicates(string s)
{
    string out;
    int i = 0, j = i+1, k = 0, l = 0, n = s.length();
    while(k<n)
    {
        // cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
        if(s[k]==s[j])
        {
            l++;
            j++;
        }
        else if(s[k]!=s[j])
        {
            if(l==0)
            {
                j++;
                k++;
            }
            else if(l!=0)
            {
                out += s.substr(i,k-i);
                j++;
                i = j - 1;
                k = i;
                l = 0;
            }
        }
    }
    out += s.substr(i,k-i);
    return out;
}

string remove_duplicates(string s)
{
    string out = "";
    int i = 0, n = s.length();
    while(i<n)
    {
        if(i==0||s[i]!=out[out.length()-1])
        {
            out+=s[i];
        }
        else if(s[i]==out[out.length()-1])
        {
            out.erase(out.length()-1);
        }
        i++;
    }
    return out;
}

int main() {
	string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        // while(check_duplicates(s))
        // {
        //     s = adj_duplicates(s);
        // }
        cout<<remove_duplicates(s)<<endl;
        // cout<<s<<endl;
    }
	return 0;
}
