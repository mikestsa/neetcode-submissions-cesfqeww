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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* copy = dummy;
        while(list1 || list2){
            int l1 = list1 ? list1->val : INT_MAX;
            int l2 = list2 ? list2->val : INT_MAX;
            if (l1 <= l2){
                dummy->next = list1;
                list1 = list1->next;
                
            }
            else{
                dummy->next = list2;
                list2= list2->next;

            }
            dummy = dummy->next;
        }
        while(list1){
            dummy->next = list1;
            list1 = list1->next;
        }
        while(list2){
            dummy->next = list2;
            list2 = list2->next;
        }
        auto out =  copy->next;
        delete copy;
        return out;
        
    }
};
