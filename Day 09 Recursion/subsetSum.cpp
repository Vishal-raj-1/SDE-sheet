void solve(vector<int> &ans, vector<int> arr, int N, int sum, int index)
{
    if (index == N)
    {
        ans.push_back(sum);
        return;
    }
    solve(ans, arr, N, sum + arr[index], index + 1);
    solve(ans, arr, N, sum, index + 1);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    solve(ans, arr, N, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}