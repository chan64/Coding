#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
void pushNode(ListNode **head_ref, int data)
{
    ListNode *new_node = new ListNode(0);
    ListNode *last = *head_ref;
    new_node->val = data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
ListNode* mergeLists(ListNode *l1, ListNode *l2)
{
    if(!l1&&!l2){
        return NULL;
    }
    if(!l1&&l2){
        return l2;
    }
    if(l1&&!l2){
        return l1;
    }
    struct ListNode *curr1 = l1;
    struct ListNode *next1 = l1->next;
    struct ListNode *curr2 = l2;
    struct ListNode *next2 = l2->next;
    while (curr1 && curr2)
    {
        if (curr1 && curr2 && curr1->val > curr2->val)
        {
            // cout << "in 43";
            // cout << "----curr1>curr2-----" << endl;
            // cout << "curr1:" << curr1->val << " next1:" << next1->val << " curr2:" << curr2->val << " next2:" << next2->val << endl;
            // res = l1;
            curr2->next = curr1;
            if (next2)
            {
                curr2 = next2;
                next2 = next2->next;
            }
            else
                break;
            // cout << "curr1:" << curr1->val << " next1:" << next1->val << " curr2:" << curr2->val << " next2:" << next2->val << endl;
            printList(curr1);
            printList(curr2);
        }
        if (curr1 && curr2 && curr1->val <= curr2->val)
        {
            // cout << "----curr1<curr2-----" << endl;
            // cout << "curr1:" << curr1->val << " next1:" << next1->val << " curr2:" << curr2->val << " next2:" << next2->val << endl;
            // res = l2;
            curr1->next = curr2;
            if (next1)
            {
                curr1 = next1;
                next1 = next1->next;
            }
            else    
                break;
            // cout << "curr1:" << curr1->val << " next1:" << next1->val << " curr2:" << curr2->val << " next2:" << next2->val << endl;
            printList(curr1);
            printList(curr2);
        }
    }
    // if (curr1->val > curr2->val)
    // {
    //     // cout << "curr1:" << curr1->val <<" curr2:" << curr2->val << endl;
    //     curr2->next = curr1;
    // }
    // if (curr1->val < curr2->val)
    // {
    //     // cout << "curr1:" << curr1->val <<" curr2:" << curr2->val << endl;
    //     curr1->next = curr2;
    // }
    if(l1->next==l2)
    {
        // cout<<"l1"<<endl;
        return l1;
    }
    if(l2->next==l1) 
    {
        // cout<<"l2"<<endl;
        return l2;
    }
    return NULL;
}

ListNode* mergeListsPearl(ListNode *l1, ListNode *l2){
    struct ListNode *needle = new ListNode(0);
    struct ListNode *needlehead = needle;

    while(l1&&l2){
        // cout<<needle->val<<" "<<l1->val<<" "<<l2->val<<endl;
        if(l1->val>l2->val)
        {
            needle->next = l2;
            l2 = l2->next;
        }
        else{
            needle->next = l1;
            l1 = l1->next;
        }
        needle = needle->next;
    }

    needle->next = l1? l1:l2;
    return needlehead->next;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, val;
        cin >> n >> m;
        struct ListNode *l1 = NULL;
        struct ListNode *l2 = NULL;
        while (n--)
        {
            cin >> val;
            pushNode(&l1, val);
        }
        while (m--)
        {
            cin >> val;
            pushNode(&l2, val);
        }
        // cout<<getMiddle(head)<<endl;
        // removeNthFromEnd(head, x);
        // printList(mergeListsPearl(l1, l2));
        cout << endl;
        // printList(reverseHelper(head));

        printList(l1);
        printList(l2);
    }
    return 0;
}