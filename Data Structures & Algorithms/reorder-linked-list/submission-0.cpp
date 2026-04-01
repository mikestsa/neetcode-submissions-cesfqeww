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
    void reorderList(ListNode* head) { 
        //if oddd 0 1 2 3 4 5 6 -> slow = 3 fast 6
        //if even 0 1 2 3 -> slow = 2 fast = null
        // start slow fast and reverse till slow
     ListNode*  slow = head;
     ListNode*  fast = head;
     while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
     }
//reverse from slow till end

    ListNode*  node = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr;
    while(node){
        ListNode* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    ListNode* left = head;
    ListNode* right = prev;
    ListNode* dummy = new ListNode();
    ListNode* copy_dummy = dummy;
    while(left || right){
        if (left){
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;
        } 
         if (right){
            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }      
    }
    dummy->next = nullptr;

        
    }
};
