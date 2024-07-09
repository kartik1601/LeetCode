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
#define tlistNode tuple<ListNode*,ListNode*,ListNode*>
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto [e,f,nxt] = reverse(nullptr,head,k);
        f->next = nxt; head = e;
        while(nxt && nxt->next){
            auto pFirst = f;
            auto t = reverse(f,nxt,k);
            e=get<0>(t); f=get<1>(t); nxt=get<2>(t);
            if(!e && !f && !nxt){break;}
            f->next = nxt;
            pFirst->next = e;
        }
        return head;
    }
    tlistNode reverse(ListNode* p=NULL, ListNode* c=NULL, int k=0){
        ListNode *first = c, *t=c;
        int cnt=0;
        while(t && cnt<k){cnt++; t=t->next;}
        if(cnt<k){return {NULL,NULL,NULL};}

        while(c && k>0){
            ListNode *nxt = c->next;
            c->next = p;
            p = c; c = nxt;
            k--;
        }
        return {p,first,c};
    }
};