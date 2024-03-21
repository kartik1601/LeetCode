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
        ListNode *l2_head = list2, *l2_tail = list2;
        while(l2_tail->next!=NULL){l2_tail=l2_tail->next;}
        
        ListNode *l1 = list1, *temp=NULL;
        int i=0;
        for(; i<a-1 ; i++){l1 = l1->next;}
        
        temp = l1->next;
        l1->next = l2_head;
        while(i<b-1){temp=temp->next; i+=1;}
        l2_tail->next = temp->next;
        temp->next = NULL;
        
        return list1;
    }
};