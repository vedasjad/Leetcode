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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second_half = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        ListNode *current = second_half;
        while (current) {
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        second_half = prev;

        ListNode *first_half = head;
        while (second_half) {
            ListNode *temp1 = first_half->next;
            first_half->next = second_half;
            ListNode *temp2 = second_half->next;
            second_half->next = temp1;
            first_half = temp1;
            second_half = temp2;
        }
    }
};