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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return memo(root,dp);
    }
    int memo(TreeNode*node,unordered_map<TreeNode*,int>&dp){
        if(!node){return 0;}
        if(dp.count(node)>0){return dp[node];}

        TreeNode *l=node->left, *r=node->right;

        int take = node->val + 
                    (l ? memo(l->left,dp)+memo(l->right,dp) : 0) + 
                    (r ? memo(r->left,dp)+memo(r->right,dp) : 0) ;
        
        int skip = memo(l,dp) + memo(r,dp);

        return dp[node] = max(take,skip);
    }
};