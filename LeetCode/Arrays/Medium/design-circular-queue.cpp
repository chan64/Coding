#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

class MyCircularQueue {
public: 
    int head = 0, tail= -1, n = 0;
    vector<int> queue = {};
    
    MyCircularQueue(int k) {
        cout<<"Initialized queue of size "<<k<<endl;
        queue.resize(k,0);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        tail = (tail+1)%queue.size();
        queue[tail] = value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())  
            return false;
        queue[head] = -1;
        head = (head+1)%queue.size();
        n--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1: queue[head];
    }
    
    int Rear() {
        return isEmpty()? -1: queue[tail];
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    bool isFull() {
        return n == queue.size();
    }

    void print_queue()
    {
        for(int i = head; i!=tail;i=((i+1)%n))
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    // MyCircularQueue *obj = new MyCircularQueue(5);
    // cout<<"Queue Before:"<<endl;
    // print_vector(obj->queue);

    // obj->enQueue(1);
    // obj->enQueue(2);
    // obj->enQueue(3);
    // obj->deQueue();
    // obj->deQueue();
    // obj->deQueue();
    // obj->deQueue();
    // obj->enQueue(4);

    // cout<<"Queue After:"<<endl;
    // print_vector(obj->queue);
    // q_front = obj->Front();
    // q_rear = obj->Rear();
    // cout<<(q_front)<<endl;
    // cout<<(q_rear)<<endl;

    MyCircularQueue *obj = new MyCircularQueue(3);
    cout<<obj->enQueue(1)<<" =obj->enQueue(1)"<<endl;
    cout<<obj->enQueue(2)<<" =obj->enQueue(2)"<<endl;
    cout<<obj->enQueue(3)<<" =obj->enQueue(3)"<<endl;
    cout<<obj->enQueue(4)<<" =obj->enQueue(4)"<<endl;
    cout<<obj->Rear()<<" =obj->Rear()"<<endl;
    cout<<obj->isFull()<<" =obj->isFull()"<<endl;
    cout<<obj->deQueue()<<" =obj->deQueue()"<<endl;
    cout<<obj->enQueue(4)<<" =obj->enQueue(4)"<<endl;
    cout<<obj->Rear()<<" =obj->Rear()"<<endl;
    obj->print_queue();
}