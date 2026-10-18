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
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    int inLeft,
                    int inRight) {

        if (inLeft > inRight) {
            return nullptr;
        }

        // Pick the next root from preorder.
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in O(1) average time.
        int mid = inorderIndex[rootValue];

        // Construct left subtree first.
        root->left = build(preorder, inLeft, mid - 1);

        // Then construct right subtree.
        root->right = build(preorder, mid + 1, inRight);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int n = inorder.size();

        inorderIndex.clear();
        preIndex = 0;

        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1);
    }
};
