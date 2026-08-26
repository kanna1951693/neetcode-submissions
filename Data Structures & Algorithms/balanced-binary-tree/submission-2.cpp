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
    bool isBalanced(TreeNode* root) {
        bool yes=true;
        is(root,yes);
        return yes;
    }
    int is(TreeNode* root,bool &yes){
        if(root==nullptr ||!yes) return 0;
        int lf=is(root->left,yes);
        int rf=is(root->right,yes);
        if(abs(lf-rf)>1) yes=false;
        return max(lf,rf)+1;
    }
};
