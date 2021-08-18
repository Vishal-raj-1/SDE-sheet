class Solution
{
public:
    bool isValid(int row, int col, char c, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(i, j, c, board))
                        {
                            board[i][j] = c;
                            if (solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.'; //backtracking step
                        }
                    }
                    //if board[i][j] is '.' and we can't place anything then
                    return false;
                }
            }
        }
        // if there is no empty place
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};