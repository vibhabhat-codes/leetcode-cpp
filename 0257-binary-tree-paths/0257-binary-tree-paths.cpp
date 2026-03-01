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
    vector<string> ans;

    void dfs(TreeNode* root, string path) {

        if (!root) return;

        // Add current node value to path
        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // If leaf node, store the path
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // Recur for left and right
        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};