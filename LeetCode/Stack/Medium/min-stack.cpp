// min-stack
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

class MinStack_Timedout
{
public:
    stack<int> st;
    MinStack_Timedout()
    {
        cout << "Inititalize minstack" << endl;
        st = {};
    }

    void push(int val)
    {
        st.push(val);
        return;
    }

    void pop()
    {
        st.pop();
        return;
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        int min = INT_MAX;
        stack<int> temp_st;
        while (!st.empty())
        {
            int top = st.top();
            if (top < min)
            {
                min = top;
            }
            temp_st.push(top);
            st.pop();
        }
        while (!temp_st.empty())
        {
            st.push(temp_st.top());
            temp_st.pop();
        }
        return min;
    }

    void print_stack(stack<int> s)
    {
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
    }
};

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
        st = {};
    }

    void push(int val)
    // Push {value, min(stack)} as pair
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(st.top().second, val)});
    }

    void pop()
    {
        st.pop();
        return;
    }

    int top()
    {
        // Pair's first element is the actual element
        return st.top().first;
    }

    int getMin()
    {
        // Pair's second element is the minimum element for entire stack
        return st.top().second;
    }

    void print_stack(stack<int> s)
    {
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << "minStack->getMin();" << minStack->getMin() << endl;
    minStack->pop();
    cout << "minStack->top();" << minStack->top() << endl;
    cout << "minStack->getMin();" << minStack->getMin() << endl;
    return 0;
}