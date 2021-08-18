int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char str[5] = {'D', 'L', 'R', 'U'};

void solve(int i, int j, vector<vector<int>> &m, int n, vector<vector<int>> &visited,
           vector<string> &ans, string s)
{

    if (i < 0 || j < 0 || i > n || j > n || m[i][j] == 0 || visited[i][j] == 1)
        return;

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && y >= 0 && x < n && y < n && m[x][y] == 1 && visited[x][y] == 0)
        {
            visited[i][j] = 1;
            solve(x, y, m, n, visited, ans, s + str[k]);
            visited[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;
    // visited[0][0] = 1;
    if (m[0][0] == 1)
        solve(0, 0, m, n, visited, ans, "");
    return ans;
}