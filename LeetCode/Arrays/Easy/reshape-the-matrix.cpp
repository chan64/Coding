#include <bits/stdc++.h>
using namespace std;

void print_2Dvector(vector<vector<int>>& mat)
{
    for(vector<int> a: mat)
    {
        for(int i: a)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> flatten(vector<vector<int>>& mat)
{
    int mat_r_size = mat.size(), mat_c_size = mat[0].size();
    printf("mat_r_size=%d, mat_c_size=%d\n", mat_r_size, mat_c_size);
    vector<int> flat_v((mat_r_size*mat_c_size), 0);
    for(int i = 0;i<mat_r_size;i++)
    {
        for(int j = 0;j<mat_c_size;j++)
        {
            int k = (mat_c_size*i)+(mat_r_size*j);
            flat_v[(mat_c_size*i)+(j)] = mat[i][j];
        }
    }
    return flat_v;
}

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if((r*c)!=(mat.size()*mat[0].size()))
    {
        return mat;
    }
    vector<int> flat_mat = flatten(mat);
    vector<vector<int>> v(r,vector<int>(c,0));
    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            v[i][j] = flat_mat[(r*i)+j];
        }
    }
    print_2Dvector(v);
    return v; 
}

int main(){
    vector<vector<int>> mat = {{1,2}, {3,4}};
    int r = 1;
    int c = 4;

    print_2Dvector(mat);
    matrixReshape(mat,r,c);
    return 0;
}

