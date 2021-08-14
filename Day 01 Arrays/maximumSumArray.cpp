// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int result = nums[0], previous = nums[0];

        for (int i = 1; i < n; i++)
        {
            previous = nums[i] + (previous > 0 ? previous : 0);
            result = max(result, previous);
        }

        return result;
    }
};