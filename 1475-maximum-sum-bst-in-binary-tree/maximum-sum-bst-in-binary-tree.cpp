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
    struct Info{
        int mx;
        int mn;
        int sum;
        bool isbst;
    };
    int maxsum;
    Info solve(TreeNode* root){
        if(root==NULL){
            return {INT_MIN,INT_MAX,0,true};
        }
        Info left=solve(root->left);
        Info right=solve(root->right);
        if(left.mx<root->val && root->val<right.mn &&left.isbst && right.isbst){
            int cur_sum=left.sum+root->val+right.sum;
            maxsum=max(cur_sum,maxsum);
            return {max(root->val,right.mx),min(root->val,left.mn),cur_sum,true};
        }
        return {INT_MIN,INT_MAX,0,false};
    } 

    int maxSumBST(TreeNode* root) {
        maxsum=0;
        solve(root);
        return maxsum;
    }
};