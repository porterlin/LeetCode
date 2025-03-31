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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* p0 = &dummyNode;
        for (int i = 0; i < left - 1; i++)
            p0 = p0->next;
        
        ListNode* pre = p0;
        ListNode* cur = p0->next;
        ListNode* nxt;
        for (int i = 0; i < right - left + 1; i++) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummyNode.next;
    }
};