/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){return nullptr;}
        Node *newHead = new Node(head->val);
        Node *curr=head, *newCurr=newHead;

        unordered_map<Node*,Node*> mp;
        mp[head]=newHead;

        while(curr){
            if(curr->random){
                if(!mp.count(curr->random)){
                    mp[curr->random] = new Node(curr->random->val);
                }
                newCurr->random = mp[curr->random];
            }

            if(curr->next){
                if(!mp.count(curr->next)){
                    mp[curr->next] = new Node(curr->next->val);
                }
                newCurr->next = mp[curr->next];
            }

            newCurr = newCurr->next;
            curr = curr->next;
        }

        return newHead;
    }
};