class Solution
{
public:
    // node it not a head to a list, its node which has to be deleted.
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        *node = *node->next;
        delete (temp);
    }
};