/*
Solution 1: Naive solution (find set bit of every number TC: O(LogN) for N number ).. TC: O(NLogN)
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);

        if (num == 0)
            return ans;

        for (int i = 0; i <= num; i++)
        {
            int temp = i;
            ans[i] = 0;
            while (temp)
            {
                ans[i]++;
                temp = temp & (temp - 1);
            }
        }
        return ans;
    }
};
/*
Solution 1: let say x = 1010 (10 in decimal), 
set bit in x equal to set bit in x/2 (here 101), if x is even 
set bit in x equal to set bit x/2 + 1 if x is odd.
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);

        if (num == 0)
            return ans;

        ans[0] = 0, ans[1] = 1;
        for (int i = 2; i <= num; i++)
            ans[i] = ans[i >> 1] + (i & 1);

        return ans;
    }
};