/*
Brute Solution : Recursion (Expontential TC)
*/

class Solution
{
public:
    int uniquePaths(int m, int n, int i = 0, int j = 0)
    {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;

        return uniquePaths(m, n, i + 1, j) + uniquePaths(m, n, i, j + 1);
    }
};

/*
Better Solution: DP (Quadratic TC)
*/

class Solution
{
public:
    int calc(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = calc(m, n, i + 1, j, dp) + calc(m, n, i, j + 1, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return calc(m, n, 0, 0, dp);
    }
};

/*
Optimal Solution: 
We need total m+n-2 moves(ie., m-1 + n-1) from which m-1 should be downward.

     (m+n-2)
ans =       C
             (m-1)
*/

class Solution
{
public:
    int uniquePaths(int m, int n, int i = 0, int j = 0)
    {
        int N = m+n-2, r = m-1;
        double ans = 1;
        for (int i = 1; i <= r; i++)
            ans = ans*(N-r+i)/i;
            
        return (int)ans;   
    }
};