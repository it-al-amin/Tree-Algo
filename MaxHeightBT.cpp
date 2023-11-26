#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int maxHeight(Node *root) // using recursion of DFS
{
    if (root == NULL)
    {
        return 0;
    }
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return 1 + max(l, r);
}
int maxHeight1(Node *root) // using level order traversal of BFS
{
    if (root == NULL)
    {
        return 0;
    }
    vector<int> lev(1000);
    lev[root->data] = 1;
    queue<Node *> q;
    q.push(root);
    int mx = 0;
    while (!q.empty())
    {
        int size = q.size();
        int l = q.front()->data;
        mx = max(mx, lev[l]);
        for (int i = 0; i < size; i++)
        {
            Node *newNode = q.front();
            q.pop();
            if (newNode->left != NULL)
            {
                Node *p = newNode->left;
                q.push(p);
                lev[p->data] = lev[l] + 1;
            }
            if (newNode->right != NULL)
            {
                Node *p = newNode->right;
                q.push(p);
                lev[p->data] = lev[l] + 1;
            }
        }
    }
    return mx;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->left = new Node(11);

    cout << maxHeight(root) << "\n"; // Fixed: Use << instead of <
    cout << maxHeight1(root) << "\n";
    return 0; // Added: Return statement for main
}
