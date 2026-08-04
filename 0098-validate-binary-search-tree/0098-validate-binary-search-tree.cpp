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
    bool validate(TreeNode* node, long long low, long long high){
        if(node==nullptr)
        return true;

        if(node->val<=low||node->val>=high)
        return false;

        return validate(node->left,low,node->val)&&validate(node->right,node->val,high);

    }


    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};