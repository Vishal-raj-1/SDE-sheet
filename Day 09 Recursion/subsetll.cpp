class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> v, int index)
    {
        if (index == nums.size())
        {
            if (find(ans.begin(), ans.end(), v) == ans.end())
                ans.push_back(v);
            return;
        }
        solve(ans, nums, v, index + 1);
        v.push_back(nums[index]);
        solve(ans, nums, v, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(ans, nums, v, 0);
        return ans;
    }
};

/*
Better Solution
*/

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &v, int index)
    {
        ans.push_back(v);
        for (int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1])
                continue;
            
            v.push_back(nums[i]);
            solve(ans, nums, v, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(ans, nums, v, 0);
        return ans;
    }
};