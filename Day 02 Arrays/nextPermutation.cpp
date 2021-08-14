
/* 
a[i] < a[i+1] find index
a[index] < a[i] 
swap(a[index], a[i]);
reverse(index+1, last);

TC: O(N), SC: O(1);
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for (int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index != -1){
            for (int i = n-1; i > index; i--)
            {
                if(nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }
        reverse(nums.begin()+index+1, nums.end());

    }
};