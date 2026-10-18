/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    unordered_map<int, int> inorderIndex;
    int postIndex = 0;

    TreeNode* build(vector<int>& postorder,
                    int inLeft,
                    int inRight) {

        if (inLeft > inRight) {
            return nullptr;
        }

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int mid = inorderIndex[rootValue];

        // Build RIGHT subtree first.
        root->right = build(postorder, mid + 1, inRight);

        // Then build LEFT subtree.
        root->left = build(postorder, inLeft, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();

        inorderIndex.clear();
        postIndex = n - 1;

        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(postorder, 0, n - 1);
    }
};
