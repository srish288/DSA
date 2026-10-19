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
  vector<vector<int>> ans;
  vector<int> path;
  void dfs(TreeNode* root,int remain){
    if(root==NULL){
        return;
    }
    path.push_back(root->val);
    remain-=root->val;
    if(root->left==NULL && root->right==NULL && remain==0){
        ans.push_back(path);
    }
    dfs(root->left,remain);
    dfs(root->right,remain);
    path.pop_back();
  }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        path.clear();
        dfs(root,targetSum);
        return ans;
    }
};