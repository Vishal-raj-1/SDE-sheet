/*
Solution 1: take xor or every element of array. TC: O(N), but it will be good for unsorted array. As array is 
sorted, we can optimise our solution using binary search. TC: O(logN).
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            //if mid is odd, then mid^1 will be prev even number, or mid is even then mid^1 will be next odd
            if (nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};