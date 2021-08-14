class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = head, *prev = dummy, *next;
        int size = 0;
        while (curr)
        {
            size++;
            curr = curr->next;
        }
        while (size >= k)
        {
            size -= k;
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
        }
        return dummy->next;
    }
};