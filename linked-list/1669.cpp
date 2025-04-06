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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* right = list1;
        int buf = b - a + 1;
        while (buf--) {
            right = right->next;
        }
        ListNode* left = list1;
        while (--a) {
            left = left->next;
            right = right->next;
        }
        
        ListNode* cur = list2;
        while (cur->next)
            cur = cur->next;
        
        left->next = list2;
        cur->next = right->next;

        return list1;
    }
};