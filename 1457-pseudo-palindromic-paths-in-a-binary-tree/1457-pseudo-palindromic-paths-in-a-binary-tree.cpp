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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        int freq[10]={0};
        solve(root,freq,ans);
        return ans;
    }
    bool isPalindrome(int freq[]){
        int odd=0;
        for(int i=1 ; i<10 ; i++){
            if(freq[i]%2){odd++;}
            if(odd>1){return false;}
        }
        return true;
    }
    void solve(TreeNode*node, int freq[], int&ans){
        freq[node->val]++;
        
        if(!node->left && !node->right){
            if(isPalindrome(freq)){ans++;}
            freq[node->val]--;
            return;
        }
        
        if(node->left){solve(node->left,freq,ans);}
        if(node->right){solve(node->right,freq,ans);}
        
        freq[node->val]--;
    }
};