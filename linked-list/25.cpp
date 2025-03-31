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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }

        ListNode dummyNode(0, head);
        ListNode* p0 = &dummyNode;
        ListNode* pre = nullptr;
        ListNode* nxt;
        cur = head;

        while (n >= k) {
            n -= k;
            for (int i = 0; i < k; i++) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummyNode.next;
    }
};