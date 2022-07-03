#include <bits/stdc++.h>
using namespace std;

vector<string> turn(string s, int i)
{
    vector<string> res(2, s);
    res[0][i] = '0' + (res[0][i] - '0' + 1) % 10;      // forward turn
    res[1][i] = '0' + (res[1][i] - '0' - 1 + 10) % 10; // backward turn
    return res;
}

int openLock(vector<string> &deadends, string target)
{
    int steps = 0;
    unordered_set<string> deadends_set(deadends.begin(), deadends.end());
    queue<string> q;
    q.push("0000");
    if (target == "0000")
        return 0;
    if (deadends_set.count("0000"))
        return -1;
    while (!q.empty())
    {
        int n = q.size();
        for (int k = 0; k < n; k++)
        {
            string current = q.front();
            string neighbours1 = current, neighbours2 = current;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                // for (auto adj_str : turn(current, i))
                // {
                //     if (seen.find(adj_str) == end(seen) && dead.find(adj_str) == end(dead)) // adjacent (turned) string is not visited earlier, nor a dead end
                //         if (adj_str == target)
                //             return minTurns;
                //         else
                //             q.push(adj_str), seen.insert(adj_str);
                // }
                neighbours1 = current, neighbours2 = current;
                neighbours1[i] = ((neighbours1[i] - '0' + 1) % 10) + '0';

                if (!deadends_set.count(neighbours1))
                {
                    if (current == target)
                        return steps;
                    deadends_set.insert(neighbours1);
                    q.push(neighbours1);
                }
                neighbours2[i] = ((10 + neighbours2[i] - '0' - 1) % 10) + '0';
                if (!deadends_set.count(neighbours2))
                {
                    if (current == target)
                        return steps;
                    deadends_set.insert(neighbours2);
                    q.push(neighbours2);
                }
                // cout << neighbours1 << " " << neighbours2 << " ";
            }
        }
        steps++;

        // cout << " " << steps << " ";
        // for (string s : deadends_set)
        // {
        //     cout << s << ",";
        // }
        // cout << endl
        //      << endl;
    }
    return -1;
}

int main()
{
    // vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888",
                               "8888"};
    string target = "8888";
    // string target = "0202";
    cout << "openLock(deadends, target):" << openLock(deadends, target) << endl;
    return 0;
}