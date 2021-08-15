/*
Solution1: Using unordered_map, store deep copy of node and node in map and then assign next and random pointer.
TC: O(N), SC: O(N)

Solution2: Three step procedure...
Step 1: Will take deep copy of every node and insert them between original list. 1->(1)->2->(2),... (1), (2) are deep copy.
Step 2: Assign Random Pointer
Step 3: Retain Original list and copy list..
TC: O(N), SC: O(1s) 
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *head_cp = NULL, *curr = head, *curr_cp = NULL;

        //Step 1
        while (curr)
        {
            curr_cp = new Node(curr->val, curr->next, NULL);
            curr->next = curr_cp;
            curr = curr_cp->next;
        }

        //Step 2:
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        //Step 3:
        curr = head;
        head_cp = curr->next;
        while (curr)
        {
            curr_cp = curr->next;
            curr->next = curr_cp->next;
            curr = curr->next;
            if (curr)
                curr_cp->next = curr->next;
        }
        return head_cp;
    }
};