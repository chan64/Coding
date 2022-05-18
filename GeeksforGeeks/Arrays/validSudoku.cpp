#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

bool isValidSudoku(vector<vector<char> >& board) {
    int row[9][9] = {}, col[9][9] = {}, subgrid[9][9] = {};
    for(int i = 0;i <board.size();i++)
    {
        for(int j = 0;j <board[i].size();j++)
        {
            if(board[i][j]!='.')
            {
                int num = board[i][j] - '0' - 1, k = i/3*3+j/3;
                if(row[i][num]||col[j][num]||subgrid[k][num])
                    return false;
                row[i][num] = col[j][num] = subgrid[k][num] = 1;
            }
            // printf("(%d,%d)=%d ", i,j, k);
            // cout<<k<<" ";
        }
        // cout<<endl;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char> > v(n, vector<char>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        cout<<"Before Swap"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // printf("(%d,%d) ",i,j);
                cout << v[i][j]<<" ";
            }
            cout<<endl;
        }
        
        string out = isValidSudoku(v)? "true":"false";
        cout<<"isValidSudoku():"<<out;

    }
    return 0;
}