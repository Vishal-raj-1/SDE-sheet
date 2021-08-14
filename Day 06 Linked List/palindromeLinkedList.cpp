class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        while (slow)
        {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};