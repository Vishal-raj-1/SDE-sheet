/*
Solution 1: Find length of list and then traverse the longer list by the diff of length and then traverse both
list simuntanously and find the intersection node. TC: O(2*lengthofbiggerlinkedList)
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA, *tempB = headB;
        int Asize = 0, Bsize = 0;
        while (tempA || tempB){
            if (tempA){
                Asize++;
                tempA = tempA->next;
            }

            if (tempB){
                Bsize++;
                tempB = tempB->next;
            }
        }

        tempA = headA, tempB = headB;
        while (Asize != Bsize){
            if (tempA && Asize > Bsize){
                Asize--;
                tempA = tempA->next;
            }

            if (tempB && Bsize > Asize){
                Bsize--;
                tempB = tempB->next;
            }
        }

        while (tempA && tempB)
        {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};

/*
Solution 2: We traverse both list simultanouly and if we reach the end of the linkedlist, we will reset pointer
to head of another linked list. TC: O(2*lengthofbiggerlinkedList) More concise code.
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode *a = headA, *b = headB;

        while(a != b){
            a = a == NULL ? headB: a->next;
            b = b == NULL ? headA: b->next;
        }
        return a;
    }
};