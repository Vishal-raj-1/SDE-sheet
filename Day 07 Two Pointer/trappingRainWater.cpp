/*
Solution1: Brute Force : Using three loops, Find water store at each index.
water[i] = min(maxleft,maxRight) - height[i]; TC: O(N^3), ..

Solution2: Better Solution: store maxLeft and maxRight in two array and now find water at ith index at O(1) time. 
TC: O(N), SC: O(2*N)
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int maxHeightLeft[n], maxHeightRight[n], water[n];

        maxHeightLeft[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            maxHeightLeft[i] = max(maxHeightLeft[i - 1], height[i]);
        }

        maxHeightRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxHeightRight[i] = max(maxHeightRight[i + 1], height[i]);
        }

        int sum = 0;
        //no need of water array, you can remove it and do sum += min(maxHeightLeft[i], maxHeightRight[i]) - height[i]
        for (int i = 0; i < n; i++)
        {
            water[i] = min(maxHeightLeft[i], maxHeightRight[i]) - height[i];
            sum += water[i];
        }

        return sum;
    }
};

/*
Solution 3: Efficient Solution: Using two pointer. TC: O(N), SC: O(1)
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, leftMax = 0, rightMax = 0, res = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    res += (leftMax - height[l]);
                l++;
            }
            else
            {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    res += (rightMax - height[r]);
                r--;
            }
        }
        return res;
    }
};