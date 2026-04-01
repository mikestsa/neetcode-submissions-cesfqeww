class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 1. Εύρεση του μέσου (Slow & Fast pointers)
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Αντιστροφή του δεύτερου μισού
        // Η λίστα χωρίζεται μετά τον slow
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // "Κόβουμε" τη λίστα στα δύο
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Συγχώνευση των δύο λιστών (Weaving)
        // head: αρχή πρώτου μισού, prev: αρχή αντιστραμμένου δεύτερου μισού
        ListNode* first = head;
        ListNode* second = prev;
        
        while (second) {
            ListNode* temp = first->next;
            first->next = second;
            second = second->next;
            first = first->next;
            first->next = temp;
            first = temp;
        }
    }
};