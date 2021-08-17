class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &v, int target, int index)
    {
        if (index == nums.size())
        {
            if (target == 0)
                ans.push_back(v);
            return;
        }

        //if i pick then i can pick many times.
        if(nums[index] <= target){
            v.push_back(nums[index]);
            solve(ans, nums, v, target - nums[index], index);
            v.pop_back();
        }
        solve(ans, nums, v, target, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, nums, v, target, 0);
        return ans;
    }
};