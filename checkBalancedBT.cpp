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
bool checkBalancedBT(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    if (abs(l - r) > 1)
    {
        return false;
    }
    bool left = checkBalancedBT(root->left);
    bool right = checkBalancedBT(root->right);
    if (!left || !right)
    {
        return false;
    }
    return true;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->right->left = new Node(11);
    cout << checkBalancedBT(root) << "\n";
    // cout << maxHeight(root) << "\n"; // Fixed: Use << instead of <
    // cout << maxHeight1(root) << "\n";
    return 0; // Added: Return statement for main
}
