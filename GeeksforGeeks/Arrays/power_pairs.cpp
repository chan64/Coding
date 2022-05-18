#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
    
    long long countPairs(int X[], int Y[], int M, int N)
    {
       long long c = 0;
       for(int i = 0; i<M; i++)
       {    
           for(int j = 0; j<N; j++)
            {
                cout<<pow(X[i],Y[j])<<"|"<<pow(Y[j],X[i])<<" ";
                // if(pow(X[i],Y[j])>pow(Y[j],X[i]))
                // {
                //     // printf("%d^%d > %d^%d\n", X[i], Y[j], Y[j], X[i]);
                //     c++;
                // }
            }
            cout<<endl;
       }
       return c;
    }

    

    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs1(int X[], int Y[], int M, int N)
    {
       long long c = 0;
       for(int i = 0; i<M; i++)
       {    
           for(int j = 0; j<N; j++)
            {
                if(pow(X[i],Y[j])>pow(Y[j],X[i]))
                {
                    // printf("%d^%d > %d^%d\n", X[i], Y[j], Y[j], X[i]);
                    c++;
                }
            }
       }
       return c;
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int M,N;
        cin>>M>>N;
        int i, a[M], b[N];
        for (int i = 0; i < M; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout<<ob.countPairs(a, b, M, N)<<endl;
    }
}