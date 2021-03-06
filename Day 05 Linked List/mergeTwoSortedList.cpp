class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *head, *curr;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }

        curr = head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                curr->next = l2;
                l2 = l2->next;
            }
            else
            {
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;

        return head;
    }
};