/*
Solution 1: Find size of list and then delete (size-n)th number. TC: O(2*N), SC: O(1)
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        n = size - n;
        if (n == 0)
            return head->next;

        temp = head;
        while (temp && --n)
            temp = temp->next;

        ListNode *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        return head;
    }
};

/*
Solution 2: Using slow and fast Pointer. TC: O(N), SC: O(1)
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        while(n--)
            fast = fast->next;

        if (fast == NULL)
            return head->next;

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};