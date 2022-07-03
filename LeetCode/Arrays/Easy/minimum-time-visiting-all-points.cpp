// minimum-time-visiting-all-points
#include <bits/stdc++.h>
using namespace std;

void print_2Dvector(vector<vector<int>> &mat)
{
    for (vector<int> a : mat)
    {
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int n = points.size(), min_time = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min_time += max(abs(points[i + 1][0] - points[i][0]), abs(points[i + 1][1] - points[i][1]));
        // if (abs(points[i + 1][0] - points[i][0]) > abs(points[i + 1][1] - points[i][1]))
        //     min_time += abs(points[i + 1][1] - points[i][1]);
        // else
        //     min_time += abs(points[i + 1][0] - points[i][0]);
    }
    return min_time;
}

int main()
{
    // vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    vector<vector<int>> points = {{3, 2}, {-2, 2}};
    print_2Dvector(points);
    // cout << points[0][1] << "," << points[1][1];
    cout << "minTimeToVisitAllPoints(points):" << minTimeToVisitAllPoints(points) << endl;
    return 0;
}