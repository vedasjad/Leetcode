/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            if (!head)
                return nullptr;

            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *first = dummy;
            ListNode *second = dummy;

            for (int i = 0; i < n + 1; ++i)
            {
                if (!second)
                    return nullptr;	
                second = second->next;
            }

            while (second)
            {
                first = first->next;
                second = second->next;
            }

            ListNode *temp = first->next;
            first->next = first->next->next;
            delete temp;

            return dummy->next;
        }
};