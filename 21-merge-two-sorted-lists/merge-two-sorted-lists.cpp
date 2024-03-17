/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            ListNode *first = list1, *second = list2, *merged = NULL, *head = NULL;
            while (first != NULL && second != NULL)
            {
                if (first->val <= second->val)
                {
                    if (head == NULL)
                    {
                        merged = first;
                        head = merged;
                    }
                    else
                    {
                        merged->next = first;
                        merged = merged->next;
                    }
                    first = first->next;
                }
                else
                {
                    if (head == NULL)
                    {
                        merged = second;
                        head = merged;
                    }
                    else
                    {
                        merged->next = second;
                        merged = merged->next;
                    }
                    second = second->next;
                }
            }
            if (first != NULL)
            {
                if (head == NULL)
                {
                    head = first;
                }
                else
                {
                    merged->next = first;
                }
            }
            if (second != NULL)
            {
                if (head == NULL)
                {
                    head = second;
                }
                else
                {
                    merged->next = second;
                }
            }
            return head;
        }
};