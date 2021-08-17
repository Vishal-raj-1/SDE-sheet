/*
solution : if we have number of n digit then there will be n! permutation.
lets say n=4, then according to this question, nums = {1,2,3,4};
total permutation will be :
if 1 is fixed {2,3,4} total 3! permutation having 1 as first digit.
if 2 is fixed {1,3,4} total 3! permutation having 1 as first digit.
if 3 is fixed {1,2,4} total 3! permutation having 1 as first digit.
if 4 is fixed {1,2,3} total 3! permutation having 1 as first digit.

Similarly, for {1,2,3} if we fixed 1st digit we can understand how many permutation will be there.

Now, let say n = 4 and k = 17. assuming 0th permutation is 1234, we need 16th permutation.
as we know there will be 6 permutation with 1 as its first digit, 2 as its first digit, ...
*/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans = "";
        k--;
        while (true)
        {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;

            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};