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
    
        int max_diameter = 0;

        int height(TreeNode* node){

        if(node==nullptr)
        return 0;

        

        int left_h=height(node->left);
        int right_h=height(node->right);
        max_diameter=max(max_diameter,left_h+right_h);
        return max(left_h,right_h)+1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return max_diameter;
    }
};