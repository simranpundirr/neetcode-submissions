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
    bool validate(TreeNode* root, long long minv, long long maxv){
        if(root==nullptr){
            return true;
        }
        if(root->val>=maxv || root->val<=minv){
            return false;
        }
        return validate(root->left,minv, root->val) && validate(root->right,root->val,maxv);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN, LLONG_MAX);
    }
};
