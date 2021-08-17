/*
Solution 1: if you have solve combination sum problem. Then you can modify your previous code a bit.
changes:
1. Sort the array
2. Now you can't choose one element more than once so do index+1 in either you choose element or not.

It will give TLE, test case solve 172/175.
*/

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &v, int target, int index)
    {
        if (index == nums.size())
        {
            if (target == 0 && find(ans.begin(), ans.end(), v) == ans.end())
                ans.push_back(v);
            return;
        }

        if (nums[index] <= target)
        {
            v.push_back(nums[index]);
            solve(ans, nums, v, target - nums[index], index + 1);
            v.pop_back();
        }
        solve(ans, nums, v, target, index + 1);
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(ans, nums, v, target, 0);
        return ans;
    }
};

/*
Solution 2: Solution of SubSet2 + combination Sum give this solution
*/
class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &v, int target, int index)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            v.push_back(nums[i]);
            solve(ans, nums, v, target - nums[i], i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(ans, nums, v, target, 0);
        return ans;
    }
};