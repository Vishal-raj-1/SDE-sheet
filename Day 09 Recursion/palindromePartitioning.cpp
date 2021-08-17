class Solution
{
public:
    bool isPalindrome(string str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start++] != str[end--])
                return false;
        }
        return true;
    }
    void solve(int index, string s, vector<string> &path, vector<vector<string>> &ans)
    {
        if (index == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }
};