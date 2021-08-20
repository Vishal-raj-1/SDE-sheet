int countNumberLessThanEqualToMid(vector<int> &row, int mid)
{
    int low = 0, high = row.size() - 1;
    while (low <= high)
    {
        int md = (high + low) >> 1;
        if (row[md] <= mid)
            low = md + 1;
        else
            high = md - 1;
    }
    return low;
}
int median(vector<vector<int>> &matrix, int r, int c)
{
    // code here
    int low = 1, high = 1e9, n = matrix.size(), m = matrix[0].size();
    while (low <= high)
    {
        int mid = (high + low) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += countNumberLessThanEqualToMid(matrix[i], mid);

        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}