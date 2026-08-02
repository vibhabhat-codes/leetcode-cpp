class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr)
            return nullptr;

        // Swap children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};