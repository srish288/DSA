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
    unordered_map<string,int> mp;
    vector<TreeNode*> ans;
    string serialize(TreeNode* root){
        if(root==NULL) return "#";
        string left=serialize(root->left);
        string right=serialize(root->right);
        string key=to_string(root->val)+","+left+","+right;
        mp[key]++;
        if(mp[key]==2){
            ans.push_back(root);
        }
        return key;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        ans.clear();
        serialize(root);
        return ans;
    }
};