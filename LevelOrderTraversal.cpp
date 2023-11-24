#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
vector<vector<int>> levelOrder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *newNode = q.front();
            q.pop();
            if (newNode->left != NULL)
            {
                q.push(newNode->left);
            }
            if (newNode->right != NULL)
            {
                q.push(newNode->right);
            }
            level.push_back(newNode->data);
        }
        ans.push_back(level);
    }
    return ans;
    
}
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    root->right->right->left = new node(11);
    vector<vector<int>> ans = levelOrder(root);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}