// moving-average-from-data-stream
#include <bits/stdc++.h>
using namespace std;

class MovingAverage
{
public:
    queue<int> q;
    int qsize, sum_so_far, current_size;

    MovingAverage(int size)
    {
        qsize = size;
        sum_so_far = 0;
        return;
    }

    double next(int val)
    {
        if (q.size() >= qsize)
        {
            sum_so_far -= q.front();
            q.pop();
        }
        sum_so_far+=val;
        q.push(val);

        return ((double)sum_so_far/(double)(q.size()));
    }
};

void method_handler(vector<string> methods, vector<string> method_params)
{
    MovingAverage *obj = NULL;
    for (int i = 0; i < methods.size(); i++)
    {
        if (methods[i] == "MovingAverage")
        {
            obj = new MovingAverage(stoi(method_params[i]));
        }
        if (methods[i] == "next")
        {
            double out = obj->next(stoi(method_params[i]));
            cout << "next = " << out << endl;
        }
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main()
{
    // ["MovingAverage", "next", "next", "next", "next"]
    // [[3], [1], [10], [3], [5]]
    vector<string> methods = {"MovingAverage", "next", "next", "next", "next"};
    vector<string> method_params = {"3", "1", "10", "3", "5"};
    method_handler(methods, method_params);
}