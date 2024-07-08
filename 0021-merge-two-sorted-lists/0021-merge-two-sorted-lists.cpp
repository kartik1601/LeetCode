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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h1=l1, *h2=l2;
        if(!h1 && h2){return h2;}
        if((!h2 && h1) || (!h1 && !h2)){return h1;}

        if(h1->val > h2->val){swap(h1,h2);}
        auto res = h1;

        while(h1 && h1->next){
            if(h1->next->val > h2->val){
                auto t = h1->next;
                h1->next = h2;
                h2 = t;
            }
            h1 = h1->next;
        }

        while(h2){
            h1->next = h2;
            h2 = h2->next;
            h1 = h1->next;
        }

        return res;
    }
};