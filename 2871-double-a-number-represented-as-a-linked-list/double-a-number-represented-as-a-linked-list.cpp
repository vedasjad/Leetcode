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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = head, *next = NULL, *prev = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr = prev;
        head = prev;
        int carry = 0, val = 0;
        while (curr) {
            val = curr->val;
            curr->val = (val * 2 + carry) % 10;
            carry = (val * 2 + carry) / 10;
            prev = curr;
            curr = curr->next;
        }
        cout << carry << endl;
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        curr = head, prev = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};