class Solution
{
public:
    int IndexOfMinElement(vector<int> &arr, int n)
    {
        int start = 0, end = n - 1, mid;

        while (start <= end)
        {
            if (arr[start] <= arr[end]) // already sorted.
                return start;

            mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n; // to avoid going out of bound.
            int next = (mid + 1) % n;

            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // check if its a pivot.
                return mid;

            else if (arr[mid] >= arr[start]) // checking for minimum element in unsorted part of array.
                start = mid + 1;

            else if (arr[mid] <= arr[end])
                end = mid - 1;
        }
        return 0;
    }

    int BinarySearch(vector<int> &arr, int start, int end, int num)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == num)
                return mid;
            else if (arr[mid] > num)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
    int search(vector<int> &arr, int num)
    {
        int n = arr.size();
        int minIndex = IndexOfMinElement(arr, n);
        int ans = BinarySearch(arr, 0, minIndex - 1, num);

        if (ans != -1)
            return ans;
        else
        {
            ans = BinarySearch(arr, minIndex, n - 1, num);
            if (ans != -1)
                return ans;
        }
        return -1;
    }
};