#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* node)
{
    while(node!=NULL)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
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

void deleteNode(ListNode* node){
    node->val = node->next->val;
    node->next = node->next->next;
}


void deleteN(ListNode* node, int& n){
    if(!node){
        return;
    }
    deleteN(node->next, n);
    n--;
    if(n==-1){
        // cout<<" "<<node->val<<" "<<node->next->val<<" "<<i<<endl;
        ListNode* temp = node->next;
        node->next = node->next->next;
        free(temp);
    }
    return;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    if(!head || !head->next)
        return NULL;
    struct ListNode *ptr = new ListNode(0);
    ptr->next = head;
    deleteN(ptr,n);
    printList(ptr->next);
    return ptr->next;
}

ListNode* reverseList(ListNode* head){
    if(!head||!head->next)
        return head;
    struct ListNode *prev = NULL;
    struct ListNode *next = head->next;
    struct ListNode *curr = head;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseRecur(ListNode* node1, ListNode* node2){
    if(!node1||!node2)
        return;
    reverseRecur(node2, node2->next);
    node2->next = node1;
    node1->next = NULL;
    return;
}
// 1->2->3->4->5
// 5->4->3->2->1
// 1,2
// 2,3
// 3,4
// 4,5

ListNode* reverseHelper(ListNode* head){
    if(!head)
        return NULL;
    struct ListNode* curr = head;
    while(curr->next){
        curr = curr->next;
        cout<<curr->val<<" ";
    }
    reverseRecur(head,head->next);
    return curr;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        // cin>>x;
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
        // cout<<getMiddle(head)<<endl;
        // removeNthFromEnd(head, x);
        printList(reverseList(head));
        // printList(reverseHelper(head));
    }
    return 0;
}