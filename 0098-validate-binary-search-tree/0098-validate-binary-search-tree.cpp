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
    bool tr(TreeNode* root, TreeNode* &prev) {
        
        if(!root) {
            return true;
        }
        
       
        bool res = tr(root->left, prev);
        
        if(!res) {
            return false;
        }
        if(prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return tr(root->right, prev);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        TreeNode* prev = nullptr;
        
        return tr(root, prev);
        
        
        
    }
};