/*
Solution : Greedy Algorithm, Why it works beacuse some of two smaller denomination is always less than next 
denomination. like 1+2 < 5, 2+5 < 10.

if we have deno[] = {1,5,6,9} like this than we can use greedy algorithm, we have to use dp then.
*/
void findMin(int V)
{
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    // Initialize result
    vector<int> ans;

    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--)
    {
        // Find denominations
        while (V >= deno[i])
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}