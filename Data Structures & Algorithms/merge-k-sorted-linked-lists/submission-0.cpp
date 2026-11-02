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

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>> pq;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        for(auto it:lists){
            if(it){
                pq.push({it->val,it});
            }
        }

        while(!pq.empty()){
            auto [val,it] = pq.top();
            pq.pop();

            temp->next = it;
            it = it->next;
            if(it && !pq.empty()){
                pq.push({it->val,it});
            }
            temp = temp->next;

        }

        return dummy->next;

    }
};
