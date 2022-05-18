#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstdio>
#define COUNT 5
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *tree)
{
    if (tree)
    {
        inorder(tree->left);
        cout << tree->val << " ";
        inorder(tree->right);
    }
}

void preorder(TreeNode *tree)
{
    if (tree)
    {
        inorder(tree->left);
        inorder(tree->right);
        cout << tree->val << " ";
    }
}

void postorder(TreeNode *tree)
{
    if (tree)
    {
        cout << tree->val << " ";
        inorder(tree->left);
        inorder(tree->right);
    }
}

void print2DUtil(TreeNode *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";

    cout << root->val << "\n";
    print2DUtil(root->left, space);
}

void print2D(TreeNode *root)
{
    print2DUtil(root, 0);
}

TreeNode *constructTree(int arr[], TreeNode *tree, int i, int n)
{
    if (i < n)
    {
        TreeNode *temp = new TreeNode(arr[i]);
        tree = temp;
        tree->left = constructTree(arr, tree->left, 2 * i + 1, n);
        tree->right = constructTree(arr, tree->right, 2 * i + 2, n);
    }
    return tree;
}

TreeNode *constructTreemap(int arr[], TreeNode *tree, int i, int n)
{
    map<int, TreeNode *> m;
    map<int, TreeNode *>::iterator mit;
    map<int, TreeNode *>::iterator mit_left;
    map<int, TreeNode *>::iterator mit_right;
    while (2 * i + 2 < n)
    {
        // mit = m.find(arr[i]);
        // if(mit==m.end())
        // {
        //     cout<<"Not Found"<<endl;
        //     TreeNode* t = new TreeNode(arr[i]);
        //     m[t->val] = t;
        // }
        // else{
        cout << "Found" << endl;
        TreeNode *tleft, *tright, *t = new TreeNode(arr[i]);
        m[t->val] = t;
        mit_left = m.find(arr[2 * i + 1]);
        mit_right = m.find(arr[2 * i + 2]);
        if (mit_left == m.end())
        {
            tleft = new TreeNode(arr[2 * i + 1]);
        }
        else
        {
            tleft = mit_left->second;
        }
        if (mit_right == m.end())
        {
            tright = new TreeNode(arr[2 * i + 2]);
        }
        else
        {
            tright = mit_right->second;
        }
        // TreeNode* tleft = new TreeNode(arr[2*i+1]);
        // TreeNode* tright = new TreeNode(arr[2*i+2]);
        m[tleft->val] = tleft;
        m[tright->val] = tright;
        t->left = tleft;
        t->right = tright;
        // }
        i++;
    }
    for (mit_left = m.begin(); mit_left != m.end(); ++mit_left)
    {
        cout << '\t' << mit_left->first
             << '\t' << mit_left->second->val << ' '
             << '\t' << ((mit_left->second->left) ? mit_left->second->left->val : -1) << ' '
             << '\t' << ((mit_left->second->right) ? mit_left->second->right->val : -1) << '\n';
    }
    mit = m.find(arr[0]);
    return mit->second;
}

TreeNode *constructTreeQueue(int arr[], TreeNode *tree, int i, int n)
{
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(arr[0]);
    int h = 0;
    q.push(root);
    while (!q.empty() && (2 * i + 2) <= n)
    {
        TreeNode *parent = q.front();
        //Create Child nodes
        if (2 * i + 1 < n && arr[2 * i + 1] != -1)
        {
            TreeNode *left = new TreeNode(arr[2 * i + 1]);
            parent->left = left;
            q.push(left);
        }
        if (2 * i + 2 < n && arr[2 * i + 2] != -1)
        {
            TreeNode *right = new TreeNode(arr[2 * i + 2]);
            parent->right = right;
            q.push(right);
        }
        //Push to queue

        //Pop parent
        q.pop();
        h++;
        i++;
    }
    // cout << h << endl;
    return root;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int maxDepthHelper(TreeNode *root, int h)
{
    if (!root)
        return h;
    h = max(maxDepthHelper(root->left, h + 1), maxDepthHelper(root->right, h + 1));
    // h = maxDepthHelper(root->left, h+1)?;
    // h = maxDepthHelper(root->right, h+1);
    return h;
}

int maxDepthR(TreeNode *root)
{
    return maxDepthHelper(root, 0);
}

int maxDepth(TreeNode *root)
{
    queue<TreeNode *> q;
    if (!root)
        return 0;
    int h = 0, nc = 0;
    q.push(root);
    while (!q.empty())
    {
        if (nc == 0)
        {
            // cout<<h<<" "<<q.size()<<endl;
            h++;
        }
        TreeNode *parent;
        nc = q.size();
        while (nc)
        {
            parent = q.front();
            if (parent->left)
            {
                // cout<<"---Push left"<<parent->left->val<<endl;
                q.push(parent->left);
            }

            if (parent->right)
            {
                // cout<<"---Push right"<<parent->right->val<<endl;
                q.push(parent->right);
            }
            nc--;
            q.pop();
        }
    }
    return h;
}

bool bstHelper(TreeNode *root, TreeNode *l, TreeNode *r)
{
    if (!root)
        return true;
    if ((l && (l->val >= root->val)))
        return false;
    if ((r && (root->val >= r->val)))
        return false;
    return bstHelper(root->left, l, root) && bstHelper(root->right, root, r);
}

bool isValidBSTR(TreeNode *root)
{
    return bstHelper(root, NULL, NULL);
}

void inorderArray(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        inorderArray(root->left, v);
        v.push_back(root->val);
        inorderArray(root->right, v);
    }
}

bool isValidBST(TreeNode *root)
{
    vector<int> v;
    inorderArray(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

bool symHelper(TreeNode *t1, TreeNode *t2)
{
    if (!t1 && !t2)
        return true;
    if (!t1 || !t2)
        return false;
    if (t1->val != t2->val)
        return false;
    return (symHelper(t1->left, t2->right) && (symHelper(t1->right, t2->left)));
}

bool isSymmetric(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return root;
    return symHelper(root->left, root->right);
}

vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > v;
    vector<int> v1;
    if (!root)
        return {{}};
    queue<TreeNode *> q;
    q.push(root);
    v1.push_back(root->val);
    v.push_back(v1);
    v1.clear();
    int nc = 0, h = 0;
    while (!q.empty())
    {
        h++;
        nc = q.size();
        v1.clear();
        while (nc--)
        {
            TreeNode *parent = q.front();
            if (parent->left)
            {
                q.push(parent->left);
                v1.push_back(parent->left->val);
            }
            if (parent->right)
            {
                q.push(parent->right);
                v1.push_back(parent->right->val);
            }
            q.pop();
        }
        if (!v1.empty())
            v.push_back(v1);
    }
    return v;
}

TreeNode *sortedArrayToBSTHelper(TreeNode *t, int l, int r, vector<int> &nums)
{
    if (l == r)
        return t;
    int mid = (l + r) / 2;
    t = new TreeNode(nums[mid]);
    printf("l=%d r=%d t->val=%d\n", l,r, t->val);
    t->left = sortedArrayToBSTHelper(t->left, l, mid, nums);
    t->right = sortedArrayToBSTHelper(t->right, mid + 1, r, nums);
    return t;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int r = nums.size();
    TreeNode *tree;
    if (r > 0)
        return sortedArrayToBSTHelper(tree, 0, r, nums);
    else
        return NULL;
}

int main()
{
    // int t;
    // cin>>t;
    // while(t--){

    // }
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout <<n<< endl;
    TreeNode *tree = constructTreeQueue(arr, tree, 0, n);

    // print2D(tree);
    // cout<< "Max Depth: "<<maxDepth(tree);
    // cout << "Valid BST: "<<isValidBSTR(tree) << endl;
    // cout<<"\nSymmetric: "<<isSymmetric(tree)<<endl;
    // inorder(tree);

    vector<int> v(arr, arr + n);
    for (int j = 0; j < v.size(); j++)
    {
            cout << v[j] << " ";
    }
    cout<<endl;
    tree = sortedArrayToBST(v);

    cout << "After convert" << endl;
    print2D(tree);
    // vector<vector<int> > v = levelOrder(tree);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<"-";
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}