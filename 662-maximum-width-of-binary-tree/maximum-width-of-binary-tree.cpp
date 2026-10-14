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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long size=q.size();
            long long mini=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                TreeNode* Node=q.front().first;
                long long curr=q.front().second-mini;
                q.pop();
                if(i==0) first=curr;
                if(i==size-1) last=curr;
                if(Node->left){
                    q.push({Node->left,2*curr+1});
                }
                if(Node->right){
                    q.push({Node->right,2*curr+2});
                }
        }
        ans=max(ans,last-first+1);
    }
    return (int)ans;
    }
};