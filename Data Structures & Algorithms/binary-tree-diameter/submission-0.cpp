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
    int maxi=INT_MIN;
private:
    int findHeight(TreeNode* root){
        if(!root) return 0;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxi = max(maxi, lh+rh);

        return 1+max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        findHeight(root);
        return maxi;
    }
};
