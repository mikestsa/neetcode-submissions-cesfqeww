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
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(auto list : lists) if (list) minHeap.push(list);
        
        ListNode* t_return = minHeap.top();
        minHeap.pop();
        if (t_return->next) minHeap.push(t_return->next);
        ListNode* curr = t_return;
        while(minHeap.size()){
            auto top = minHeap.top();
            minHeap.pop();
            if (top->next) minHeap.push(top->next);
            curr->next = top;
            curr = curr->next;
        }
        curr->next = nullptr;
        return t_return;
    }
};
