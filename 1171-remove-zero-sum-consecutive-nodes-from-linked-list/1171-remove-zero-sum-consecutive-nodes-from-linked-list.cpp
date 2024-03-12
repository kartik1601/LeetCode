class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> mp;
        
        while(current) {
            prefixSum += current->val;
            if (mp.find(prefixSum) != mp.end()) {
                ListNode* prev = mp[prefixSum];
                current = prev->next;
                
                int p = prefixSum + current->val;
                while (p != prefixSum) {
                    mp.erase(p);
                    current = current->next;
                    p += current->val;
                }
                prev->next = current->next;
            } else {
                mp[prefixSum] = current;
            }
            current = current->next;
        }
        return front->next;
    }
};