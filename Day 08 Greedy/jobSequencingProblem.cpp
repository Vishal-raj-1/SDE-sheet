class Solution
{
public:
    bool compare(Job a, Job b)
    {
        return b.profit < a.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].dead > maxi)
                maxi = arr[i].dead;
        }
        vector<int> sequence(maxi + 1, -1);

        int countJob = 0, countProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                // free slot found
                if (sequence[j] == -1)
                {
                    sequence[j] = arr[i].id;
                    countJob++;
                    countProfit += arr[i].profit;
                    break;
                }
            }
            vector<int> ans(2);
            ans[0] = countJob, ans[1] = countProfit;
            return ans;
        }
    }
};