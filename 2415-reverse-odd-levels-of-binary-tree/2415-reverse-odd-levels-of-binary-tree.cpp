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
    void insert(TreeNode* root, TreeNode* & cp) {
        
      if(!root) {
          return;
      }
      TreeNode* here = new TreeNode(root->val);
       insert(root->right, here->left);
       insert(root->left, here->right);
       cp = here;
        
        
        
    }
    
    void trav(TreeNode* root, TreeNode* cp, int val) {
        
        if(!root) {
            return;
        }
        
        if(val%2) {
            root->val = cp->val;
        }
        
        trav(root->left, cp->left, val+1);
        trav(root->right, cp->right, val+1);
    }
    
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        vector<int> vals;
        
        TreeNode* cp;
        
        insert(root, cp);
        
        trav(root, cp, 0);
        
        return root;
        
        
    }
};