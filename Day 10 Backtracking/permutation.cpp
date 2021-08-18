/*
Solution 1: will use one map for marking element as taken or not. If element is not taken then we will add it to 
our vector and try all combination, as soon as our vector size equals to input vector size we will add our vector 
to ans. TC: O(N!*N), N! permutation will be there and we need O(N) to generate one permutation, 
SC: O(N) for map + O(N) for recursive call stack.
*/

class Solution {
public:
    void solve(vector<int> nums, vector<int>v, vector<vector<int>>&ans, vector<int> &s){
        if(nums.size() == v.size()){
            ans.push_back(v);
            return ;
        }
        for(int i=0; i<nums.size(); i++){
            if(s[nums[i] + 10] == 0){
                s[nums[i] + 10] = 1;
                v.push_back(nums[i]);
                solve(nums, v, ans, s);
                v.pop_back();
                s[nums[i] + 10] = 0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>s(21, 0); //nums varry from -10 to 10. you can use unordered_set as well.
        solve(nums, v, ans, s);
        return ans;
    }
};

/*
Solution 2: By Swapping (0 to n-1)th index value with index+1 to n-1. 
TC: O(N!*N), SC:O(N)(not using any extra space, but it will have callstack memory consumption because of recursion)
*/

class Solution {
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(index+1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0, nums, ans);
        return ans;
    }
};