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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tempa=list1, *tempb=list1;
        int i=0;
        while(i<b){
            if(i<a-1){tempa=tempa->next;}
            tempb=tempb->next;
            i++;
        }
        
        tempa->next = list2;
        while(tempa->next){tempa=tempa->next;}
        tempa->next = tempb->next;
        
        return list1;
    }
};