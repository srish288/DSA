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

    TreeNode* recover(string traversal , int depth,int &i){
        int n=traversal.size();
      
        if(i>=n){
            return nullptr;
        }
        int j=i;
        int dashes=0;
        while(j<n && traversal[j]=='-'){
            j++;
            dashes++;
        }
         if(dashes!=depth){
            return nullptr;
        }
         i=j;
        int value=0;
        while(i<n && isdigit(traversal[i])){
             value=value*10+(traversal[i]-'0');
             i++;
        }
        TreeNode* root=new TreeNode(value);
        root->left=recover(traversal,depth+1,i);
        root->right=recover(traversal,depth+1,i);
       return root;

    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return recover(traversal,0,i);
    }
};