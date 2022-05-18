#include<bits/stdc++.h>
using namespace std;

string filter_char1(string s, bool &is_negative){
    string filter_str = "";
    bool num_came = false;
    for(int i = 0;i<s.size();i++)
    {
        if(((int)s[i]>47 && (int)s[i]<58))
        {
            filter_str+=s[i];
            num_came = true;
        }
        if((int)s[i]==45&&!num_came)
        {
            is_negative=true;
        }
    }    
    return filter_str;
}

string filter_char(string s, bool &is_negative){
    string filter_str = "";
    bool sign_came = false;
    int i = 0;
    while((int)s[i]==32)
    {
        // cout<<"(space) ";
        i++;
    }
    // cout<<endl;
    while(i<s.size())
    {
        // printf("i=%d, s[%d]=%d, sign_name=%d\n", i, i, s[i], sign_came);
        if((int)s[i]==45&&!sign_came)
        {
            is_negative=true;
            sign_came=true;
        }
        else if((int)s[i]==43&&!sign_came)
        {
            is_negative=false;
            sign_came=true;
        }
        else if(((int)s[i]>47 && (int)s[i]<58))
        {
            filter_str+=s[i];
            sign_came=true;
        }
        else
        {
            return filter_str;
        }
        i++;
    }
    return filter_str;
}

int myAtoi1(string s) { 
    bool is_negative = false;

    // cout<<"s="<<s<<endl;
    // cout<<"is_negative="<<is_negative<<endl; 

    s = filter_char(s, is_negative); 
    
    // cout<<"s="<<s<<endl;  
    // cout<<"is_negative="<<is_negative<<endl;  

    int i = s.size()-1, n = s.size()-1, num = 0;
    while(i>=0)
    {
        // cout<<num<<" ";
        // cout<<s[i]<<endl;
        // printf("i=%d, n=%d s[%d]=%c, num=%d\n", i, n, i, s[i], num);
        s[i] = s[i] - '0';
        if((-(s[i]*pow(10,n-i)<INT_MIN)&&is_negative))
        {
            return INT_MIN;
        }
        if(((s[i]*pow(10,n-i)>INT_MAX)&&!is_negative))
        {
            return INT_MAX;
        }
        num+= s[i]*pow(10,n-i);
        i--;
    }
    // int i = 0, n = s.size()-1, num = 0;
    // while(i<s.size())
    // {
    //     printf("i=%d, n=%d s[%d]=%c, num=%d\n", i, n, i, s[i], num);
    //     s[i] = s[i] - '0';
    //     if((num<INT_MIN/10)&&(is_negative))
    //     {
    //         return INT_MIN;
    //         // &&(s[i]*pow(10,n)<INT_MAX%10)
    //     }
    //     if((num>INT_MAX/10)&&(!is_negative))
    //     {
    //         return INT_MAX;
    //         // &&(s[i]*pow(10,n)>INT_MAX%10)
    //     }
    //     cout<<n<<"+"<<s[i]*pow(10,n)<<endl;
    //     num+= s[i]*pow(10,n);
    //     i++;
    //     n--;
    // }
    if(is_negative)
        num = -num;
    cout<<endl;
    return num;
}

int myAtoi(string s)
{
    int i = 0, sign = 1, num = 0;

    //Remove whitespaces
    while(s[i]==' ')
        i++;

    //Identify Sign
    if(s[i]=='-')
    {
        sign = -1;
        i++;
    }
    else if(s[i]=='+')
    {
        sign = 1;
        i++;
    } 
    else   
        sign = 1;

    cout<<s<<" "<<i<<endl;

    //Take digit strings and convert to int
    while(s[i]>='0'&&s[i]<='9')
    {
        if(num>(INT_MAX/10)|| (num==INT_MAX/10&&(s[i]-'0')>INT_MAX%10))
        {
            if(sign==-1)
                return INT_MIN;
            else
                return INT_MAX;    
        }
        // cout<<s[i]<<endl;
        num = num * 10 + (s[i]-'0');
        i++;
    }
    return num*sign;
}

int main(){
    // string s = "  +149 with +24twords";
    string s = "  42";
    int out = myAtoi(s);
    cout<<"myAtoi("<<s<<")="<<out<<endl;
}