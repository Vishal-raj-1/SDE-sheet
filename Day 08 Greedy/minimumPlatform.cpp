int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform = 1, answer = 1, i = 1, j = 0;
    while (i < n && j && n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        if (answer < platform)
            answer = platform;
    }
    return answer;
}