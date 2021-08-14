// https://leetcode.com/problems/sort-colors/

/*
    Solution 1: Naive Solution
    count number of zeros, ones and twos and overwrite the array.
    TC: O(2N) : Two pass required, SC: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zero++;
            else if(nums[i] == 1)
                one++;
            else 
                two++;
        }
        for(int i=0; i<nums.size(); i++){
            if(i<zero)
                nums[i] = 0;
            else if(i<zero+one)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

/*
    Solution 2: Using three pointer/flag.
    assuming a[0...low-1] = 0 and a[high+1...n] = 2.
    TC: O(N), SC: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++, mid++;
            }
            else if(nums[mid] == 2){
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
            else    
                mid++;
        }
        
    }
};