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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyNode(0, head);
        ListNode* cur = head;
        ListNode* pre = &dummyNode;

        ListNode* nxt;
        ListNode* nxt1;
        
        while (cur && cur->next) {
            nxt = cur->next;
            nxt1 = nxt->next;
            pre->next = nxt;
            nxt->next = cur;
            cur->next = nxt1;

            pre = cur;
            cur = nxt1;
        }
        return dummyNode.next;
    }
};