int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (m < n)
        return (arr2, arr1, m, n, k);

    int low = max(0, k - m), high = min(n, k);
    while (low <= high)
    {
        int cnt1 = (low + high) >> 1;
        int cnt2 = k - cnt1;

        int left1 = cnt1 == 0 ? INT_MIN : arr1[cnt1 - 1];
        int left2 = cnt2 == 0 ? INT_MIN : arr2[cnt2 - 1];

        int right1 = cnt1 == n ? INT_MAX : arr1[cnt1];
        int right2 = cnt2 == m ? INT_MAX : arr2[cnt2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
            high = cnt1 - 1;
        else
            low = cnt1 + 1;
    }
    return 1;
}