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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> mp;
        for(int num : nums){mp[num] = true;}

        ListNode *res = new ListNode(0);
        ListNode *curr=head, *ans=res;
        while(curr){
            if(!mp.count(curr->val)){
                ListNode *temp = new ListNode(curr->val);
                res->next = temp;
                res = res->next;
            }
            curr = curr->next;
        }

        return ans->next;
    }
};