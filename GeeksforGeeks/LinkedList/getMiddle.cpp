#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
void printList(ListNode* ListNode)
{
    while(ListNode!=NULL)
    {
        cout<<ListNode->val<<" ";
        ListNode = ListNode->next;
    }
    cout<<endl;
}

int getMiddle(ListNode *head);

bool isPalindrome(ListNode* head) {
    stack<int> s;
    struct ListNode* stackptr = head;
    while(stackptr){
        // cout<<stackptr->val<<" ";
        s.push(stackptr->val);
        stackptr = stackptr->next;
    }
    while(!s.empty()){
        if(s.top()==head->val)
        {
            // cout<<s.top()<<" "<<head->val<<endl;
            s.pop();
            head = head->next;
        }
        else{
            return false;
        }
    }
    return true;
}

bool isPalindromeO1(ListNode* head) {
    if(!head||!head->next){
        return true;
    }
    struct ListNode* prev = NULL;
    struct ListNode* next = head->next;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast&&fast->next){
        fast = fast->next->next;
        slow->next = prev;
        prev = slow;
        slow = next;
        next = next->next;
    } 
    printList(prev);
    printList(slow);
    if(slow->next)
        slow = (prev->val == slow->next->val)? slow->next: slow;
    while(prev&&slow){
        if(prev->val!=slow->val)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}

bool hasCycle(ListNode *head){
    if(!head)
    {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int val;
        cin>>val;
        struct ListNode *head = new ListNode(val);
        struct ListNode *tail = head;
        for(int i = 0;i<n-1;++i)
        {
            cin>>val;
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        // head->next->next = head;
        // printList(head);
        // cout<<getMiddle(head)<<endl;
        // cout<<isPalindromeO1(head)<<endl;
        cout<<hasCycle(head)<<endl;
    }
    return 0;
}
int getMiddle(ListNode *head)
{
   struct ListNode *slow = head;
   struct ListNode *fast = head;
   if(head){
       while(fast&&fast->next)
       {
           slow = slow->next;
           fast = fast->next->next;
       }
   }
   return slow->val;
}