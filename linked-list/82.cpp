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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1, head);
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                while (cur->next && cur->next->val == val) {
                    ListNode* nxt = cur->next;
                    cur->next = cur->next->next;
                    delete nxt;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};