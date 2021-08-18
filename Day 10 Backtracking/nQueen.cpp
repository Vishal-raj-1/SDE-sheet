/*
Solution 1: Using Backtracking, here in Time complexity of isSafe() will be O(3*N) 
*/

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        //check in the same row
        for (int i = 0; i < col; i++)
            if (board[row][i] == 'Q')
                return false;

        //in upper diagonal
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0)
            if (board[i--][j--] == 'Q')
                return false;

        //lower diagonal
        i = row, j = col;
        while (i < n && j >= 0)
            if (board[i++][j--] == 'Q')
                return false;

        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        // initializing empty board[i][j] with '.'
        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(0, board, ans, n);
        return ans;
    }
};

/*
Solution 2: Using Backtracking + hashing, here Time complexity for checking isSafe will be O(1). 
*/

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, 
                vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0)
            {
                leftRow[row] = 1, lowerDiagonal[row+col] = 1, upperDiagonal[n-1 + col-row] = 1;
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0, lowerDiagonal[row+col] = 0, upperDiagonal[n-1 + col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        // initializing empty board[i][j] with '.'
        for (int i = 0; i < n; i++)
            board[i] = s;

        vector<int>leftRow(n, 0), lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1, 0);
        solve(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};