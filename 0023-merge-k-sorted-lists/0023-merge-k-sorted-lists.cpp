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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){return {};}
        return mergeSort(lists,0,lists.size()-1);
    }
    ListNode* mergeSort(vector<ListNode*>&v,int l,int r){
        if(l==r){return v[l];}

        int mid = (r-l)/2+l;
        auto l1 = mergeSort(v,l,mid);
        auto l2 = mergeSort(v,mid+1,r);

        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1 && !l2){return l1;}
        if(!l1 && l2){return l2;}
        if(l1 && !l2){return l1;}

        if(l1->val > l2->val){swap(l1,l2);}

        ListNode *h1=l1, *h2=l2;

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

        return l1;
    }
};