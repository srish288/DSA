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
public:
      int dfs(TreeNode* root,int maxsofar){
        if(root==NULL) return 0;
        int good=0;
        if(maxsofar<=root->val){
            good=1;
        }
        int newmax=max(maxsofar,root->val);
        return good+dfs(root->left,newmax)+dfs(root->right,newmax);
      }
   
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};