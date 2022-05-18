#include<bits/stdc++.h>
using namespace std;

int compute_lps_i(char *pat, int k){
    int i = 0, j = k-1, count = 0;
    while(i<k&&j>0)
    {
        // printf("pat[%d]=%c pat[%d]=%c %d\n",i,pat[i],j,pat[j], count);
        if(pat[i]==pat[j])
        {
            i++;
            j--;
            // printf("pat[%d]=%d pat[%d]=%d %d\n",i,pat[i],j,pat[j], count);
            count++;
        }
        else{
            return count;
        }   
    }
    return count;
}

void kmp_algorithm(char *txt, char *pat)
{
    cout<<"Finding "<<pat<<" in "<<txt<<endl;
    int n = strlen(pat);
    for(int i = 0;i<n;i++)
        cout<<i<<" "<<compute_lps_i(pat,i)<<" "<<pat[i]<<endl;
    return;
}

int main(){
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABAACAABAA";
    kmp_algorithm(txt,pat);
    cout<<pat<<endl;
    return 0;
}