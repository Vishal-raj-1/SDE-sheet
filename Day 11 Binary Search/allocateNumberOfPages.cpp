bool isPossible(int *a, int n, int k, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > curr_min)
            return false;
        if (curr_sum + a[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = a[i];

            if (studentsRequired > k)
                return false;
        }
        else
            curr_sum += a[i];
    }
    return true;
}

int FindPages(int *a, int n, int k)
{
    long long sum = 0;
    // Number of books is less than number of student
    if (n < k)
        return -1;

    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (start < a[i])
            start = a[i];

        sum += a[i];
    }

    int end = sum, result = sum;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(a, n, k, mid))
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return result;
}