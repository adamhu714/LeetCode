/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *fast = head, *slow = head, *entry = head;
        
        while (fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next; 
            
            if (fast == slow) {
                while (entry != slow) {
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};