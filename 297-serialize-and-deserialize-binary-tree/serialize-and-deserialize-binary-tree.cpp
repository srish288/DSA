/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    
class Codec {
public:

    // Convert tree into a string
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                s += "#,";
            } 
            else {
                s += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    // Convert string back into a tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Rebuild left child
            if (!getline(ss, str, ',')) break;

            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Rebuild right child
            if (!getline(ss, str, ',')) break;

            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));