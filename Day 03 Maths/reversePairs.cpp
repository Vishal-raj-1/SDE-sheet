class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right){
        int count = 0, j = mid+1, i;
        for (i = left; i <= mid; i++)
        {
            //2ll == (long long)2, It is required to avoid int overflow as 2*nums[j]. 
            while (j <= right && (nums[i] > 2ll*nums[j])) 
                j++;
            
            count += (j-(mid+1)); 
        }
        vector<int>temp;
        i = left, j = mid+1;
        while(i <= mid && j <= right){
            if(nums[i] > nums[j])
                temp.push_back(nums[j++]);
            else
                temp.push_back(nums[i++]);
        }

        while(i <= mid)
            temp.push_back(nums[i++]);

        while (j <= right)
            temp.push_back(nums[j++]);

        for ( i = left; i <= right; i++)
            nums[i] = temp[i-left];
        
        return count;
    }
    int mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return 0;

        int mid = left + (right-left)/2;
        int count = mergeSort(nums, left, mid);
        count += mergeSort(nums, mid+1, right);
        count += merge(nums, left, mid, right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};