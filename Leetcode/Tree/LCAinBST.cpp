#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search a node
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return search(root->left, key);

    return search(root->right, key);
}

// Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    while (root != NULL) {

        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }

        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }

        else {
            return root;
        }
    }

    return NULL;
}

int main() {

    TreeNode* root = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int x, y;
    cout << "Enter two nodes: ";
    cin >> x >> y;

    TreeNode* p = search(root, x);
    TreeNode* q = search(root, y);

    if (p == NULL || q == NULL) {
        cout << "One or both nodes not found.";
        return 0;
    }

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor = " << ans->val;

    return 0;
}