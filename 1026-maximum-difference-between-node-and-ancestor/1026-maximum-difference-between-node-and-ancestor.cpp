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
    int maxAncestorDiff(TreeNode* node,int mx=INT_MIN,int mn=INT_MAX) {
        if(!node){return mx-mn;}
        
        mx=max(mx,node->val);
        mn=min(mn,node->val);
        
        return max(maxAncestorDiff(node->left,mx,mn),maxAncestorDiff(node->right,mx,mn));
    }
};