#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n = s.size();
    if(n==1)
        return false;
    stack<char> st;
    for(char c: s)
    {
        if(c=='('||c=='['||c=='{')
        {
            st.push(c);
        }

        else if(c==')'&&(!st.empty())&&st.top()=='(')
        {
            st.pop();
        }

        else if(c==']'&&(!st.empty())&&st.top()=='[')
        {
            st.pop();
        }

        else if(c=='}'&&(!st.empty())&&st.top()=='{')
        {
            st.pop();
        }
        else
            return false;

    }
    if(!st.empty())
        return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        string out = isValid(s)? "true":"false";
        printf("isValid(%s) = %s\n", s.c_str(), out.c_str());
    }
    return 0;
}