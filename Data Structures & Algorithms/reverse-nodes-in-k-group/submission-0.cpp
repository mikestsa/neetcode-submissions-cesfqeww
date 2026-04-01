class Solution {
public:
    // Βοηθητική για το μέγεθος
    int total_size(ListNode* head) {
        int s = 0;
        while (head) {
            s++;
            head = head->next;
        }
        return s;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        int count = total_size(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* nex = dummy;
        ListNode* pre = dummy;
        
        // Όσο έχουμε τουλάχιστον k κόμβους να αντιστρέψουμε
        while (count >= k) {
            curr = pre->next;
            nex = curr->next;
            // Η κλασική αντιστροφή ανάμεσα σε pre και nex για k-1 βήματα
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }
        
        ListNode* res = dummy->next;
        delete dummy; // clean up
        return res;
    }
};