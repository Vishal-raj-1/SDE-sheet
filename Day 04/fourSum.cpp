/*
Generalizing for kSum Problem. sort the array and use two pointer approach and wrap two sum with k-2 loop for 4sum.
TC: O(N^3) : 
We are removing duplicate, that's why there are so many while loops.
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
            return ans;

        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 3)
        {
            int j = i + 1;
            while (j < n - 2)
            {
                int left = j + 1, right = n - 1, target2 = target - nums[i] - nums[j];
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > target2)
                    {
                        int val = nums[right];
                        while (left < right && val == nums[right])
                            right--;
                    }
                    else if (sum < target2)
                    {
                        int val = nums[left];
                        while (left < right && val == nums[left])
                            left++;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int val = nums[left];
                        while (left < right && val == nums[left])
                            left++;

                        val = nums[right];
                        while (left < right && val == nums[right])
                            right--;
                    }
                }
                int val = nums[j];
                while (j < n - 2 && val == nums[j])
                    j++;
            }
            int val = nums[i];
            while (i < n - 3 && val == nums[i])
                i++;
        }

        return ans;
    }
};