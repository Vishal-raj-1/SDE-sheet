#include <iostream>
using namespace std;
//Solution 1: Using Insertion Sort TC: O(ab)
void mergeTwoSortedArr(int arr1[], int a, int arr2[], int b)
{
    for (int i = 0; i < a; i++)
    {
        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            //insertion sort
            int j = 1, val = arr2[0];
            while (j < b && arr2[j] < val)
            {
                arr2[j - 1] = arr2[j];
                j++;
            }

            arr2[j - 1] = temp;
        }
    }
}

//Solution 2: Using GAP TC: O(a+b)
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge(int arr1[], int a, int arr2[], int b)
{
    int i, j, gap = a + b;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < a; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        for ( j = gap > a ? gap-a: 0; i < a && j < b; i++,j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        
        if (j < b)
        {
            for (i = 0; i + gap < b; i++)
                if (arr2[i] > arr2[i + gap])
                    swap(arr2[i], arr2[i + gap]);
        }
    }
}
int main()
{
    int a, b;
    cout << "Enter two number : ";
    cin >> a >> b;
    int arr1[a], arr2[b];
    for (int i = 0; i < a; i++)
        cin >> arr1[i];

    for (int i = 0; i < b; i++)
        cin >> arr2[i];
    // mergeTwoSortedArr(arr1, a, arr2, b);
    merge(arr1, a, arr2, b);

    for (int i = 0; i < a; i++)
        cout << arr1[i] << " ";

    for (int i = 0; i < b; i++)
        cout << arr2[i] << " ";
    return 0;
}