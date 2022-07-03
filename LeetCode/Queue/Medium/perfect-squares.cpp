// perfect-squares
#include <bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
    int out = 0;
    if (n == 0 || n == 1)
    {
        return n;
    }
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int size = q.size();
        while (size)
        {
            // cout << "\n"
            //  << size << " - ";
            int key = q.front();
            for (int i = 1; i * i <= key; i++)
            {
                if (key - (i * i) == 0)
                    return out + 1;
                else
                {
                    // cout << key - (i * i) << " ";
                    q.push(key - (i * i));
                }
            }
            q.pop();
            size--;
        }
        // cout << endl;
        out++;
    }

    return out + 1;
}

int main()
{
    int n = 13;
    int result = numSquares(n);
    cout << "\nnumSquares(" << n << ")=" << result << endl;
    return 0;
}