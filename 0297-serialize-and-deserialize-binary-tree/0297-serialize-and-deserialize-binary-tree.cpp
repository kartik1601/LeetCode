/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> v;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){return "null";}
        
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                if(node==NULL){res+='n'; v.push_back(INT_MAX); continue;}
                res += 'x'; v.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res){
        if(res=="null"){return nullptr;}

        TreeNode *head = new TreeNode(v[0]);
        queue<TreeNode*> q; q.push(head);
        int idx=0, n=v.size();
        while(!q.empty()){
            auto node = q.front(); q.pop();
            int l=2*idx+1, r=2*idx+2;
            if(l<n){
                if(res[l]=='n'){node->left=nullptr;}
                else{node->left = new TreeNode(v[l]);}
            }
            if(r<n){
                if(res[r]=='n'){node->right = nullptr;}
                else{node->right = new TreeNode(v[r]);}
            }

            if(res[l]!='n'){q.push(node->left);}
            if(res[r]!='n'){q.push(node->right);}
            idx+=1;
        }

        v.clear();
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));