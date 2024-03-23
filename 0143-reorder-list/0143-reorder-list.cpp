/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head;
        stack<ListNode*> reverse;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast && !fast->next){slow=slow->next;}
        while(slow){
            reverse.push(slow);
            slow=slow->next;
        }
        
        ListNode *curr=head;
        while(curr && curr->next && !reverse.empty()){
            ListNode *nxt = reverse.top(); reverse.pop();
            ListNode *temp = curr->next;
            curr->next = nxt;
            nxt->next = temp;
            curr = curr->next->next;
        }
        
        if(curr){curr->next=nullptr;}
    }
};