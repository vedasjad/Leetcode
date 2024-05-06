/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* curr = head;
        int val=0;
        while (curr) {
            val = curr->val;
            while (!stk.empty() && stk.top()->val < val) {
                stk.pop();
            }
            stk.push(curr);
            curr=curr->next;
        }
        curr = NULL;
        while(!stk.empty()){
            head = stk.top();
            head->next=curr;
            curr=head;
            stk.pop();
        }
        return head;
    }
};