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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pos;
        for(int i=0;i<inorder.size();i++){
            pos[inorder[i]]=i;
        }
        int preindex=0;
        return build(preorder, inorder, preindex, 0, inorder.size()-1,pos);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preindex, int left, int right, unordered_map<int,int>& pos){
        if(left>right){
            return nullptr;
        }
        int rootvalue=preorder[preindex++];
        TreeNode* root=new TreeNode(rootvalue);
        int mid=pos[rootvalue];
        root->left=build(preorder, inorder, preindex, left, mid-1, pos);
        root->right=build(preorder,inorder, preindex, mid+1, right, pos);
        return root;
    }
};
