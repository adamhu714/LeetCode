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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ret_head = nullptr, **pre = nullptr, *cur = nullptr;
        while (head) {
            cur = head;
            head = head -> next;
            pre = &ret_head;
            while (*pre && (*pre) -> val < cur -> val) {
                pre = &(*pre) -> next;
            }
            cur -> next = *pre;
            *pre = cur;
        }
        return ret_head;
    }
};