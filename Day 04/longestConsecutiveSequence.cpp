class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;

        for (int i : s)
        {
            if (s.find(i - 1) == s.end())
            {
                int x = i + 1;

                while (s.find(x) != s.end())
                {
                    x++;
                }
                result = max(result, x - i);
            }
        }
        return result;
    }
};