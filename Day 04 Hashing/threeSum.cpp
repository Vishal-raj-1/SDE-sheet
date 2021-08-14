class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3)
            return ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    //jump over duplicates
                    int val = nums[left];
                    while(left < right && val == nums[left])
                        left++;

                    val = nums[right];
                    while(left < right && val == nums[right])
                        right--; 
                }
            }
            //jump over duplicates
            while(i < n-2 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};