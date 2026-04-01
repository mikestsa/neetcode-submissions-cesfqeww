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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* return_val = head;
        int len = 0;
        ListNode* node = head;
        while(node){
            len++;
            node = node->next;
        }
        int remove_from_beg = len - n;
        if (remove_from_beg == 0) return head->next;
        node = head;
        ListNode* prev = head;
        while(remove_from_beg){
            prev = node;
            node = node->next;
            remove_from_beg--;
        }
        if (!node) prev->next = nullptr;
        else prev->next = node->next;
        return return_val;
        
    }
};
