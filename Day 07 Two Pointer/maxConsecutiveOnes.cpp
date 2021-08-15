class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                count++;
            else
                count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};