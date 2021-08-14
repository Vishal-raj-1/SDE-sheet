/*
Solution: Point last node of list to first node k time. k will be max n-1. TC: O(N^2). 
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(!head || k == 0)
            return head;
        ListNode *curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        k = k%len;
        while(k--){
            curr = head;
            ListNode* prev = head;
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};

/*
Solution2: After Pointing last node of list to first, it will be circular list. And you have to assign length-kth
 node (from last node) next to null. 
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        //edge case
        if(!head || !head->next || k == 0)
            return head;

        //length of list
        ListNode *curr = head;
        int len = 1;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        //make circular list, point last node next to first node.
        curr->next = head;
        k = k%len;
        k = len-k;
        
        while(k--)
            curr = curr->next;

        head = curr->next;
        curr->next = NULL;
        return head;
    }
};