#include <bits/stdc++.h>
using namespace std;
//Longest path between any two nodes
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
int maxHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = maxHeight(root->left);

    int r = maxHeight(root->right);

    return 1 + max(l, r);
}
void diameterOfBT(Node *root, int *mx, Node *&expectedRoot) // Assumption root;left+right=maxlenght that max diameter
{
    if (root == NULL)
    {
        return;
    }
    Node *ans = root;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    if (*mx < l + r)
    {
        *mx = l + r;
        expectedRoot = root;
    }
    diameterOfBT(root->left, mx, expectedRoot);
    diameterOfBT(root->right, mx, expectedRoot);
}
Node *maxHeightLeafNode(Node *root) // using level order traversal of BFS
{
    if (root == NULL)
    {
        return root;
    }
    vector<int> lev(1000);
    lev[root->data] = 1;
    queue<Node *> q;
    q.push(root);
    int mx = 1;
    Node *ans = root;
    while (!q.empty())
    {
        int size = q.size();
        int l = q.front()->data;
        if (mx < lev[l])
        {
            mx = lev[l];
            ans = q.front();
        }
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
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(13);
    root->right->left->left = new Node(70);
    root->right->left->left->left = new Node(17);
    root->left->right->left = new Node(11);
    int k = 0, mm = 0;
    Node *d = root;
    diameterOfBT(root, &k, d); // found assumption root;
    cout << d->data << "\n";
    Node *rootNode = maxHeightLeafNode(d); //  actual root node

    cout << "Max Diameter " << k << " Root Node of max diameter " << rootNode->data << "\n";

    return 0;
}
