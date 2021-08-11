/*
TC: O(Log(m*n))
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), low = 0, high = m*n - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int row = mid / n, col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};