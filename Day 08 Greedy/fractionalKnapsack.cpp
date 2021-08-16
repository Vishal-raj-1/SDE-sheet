bool compare(const Item a, const Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    retrun r1 > r2;
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, compare);
    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].weight;
        }
        else
        {
            int remain = W - currentWeight;
            finalValue += ((double)arr[i].value / arr[i].weight) * (double)remain;
        }
    }
    return finalValue;
}
