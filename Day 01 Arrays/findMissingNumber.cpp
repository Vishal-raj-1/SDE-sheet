#include<iostream>
using namespace std;

int findMissingNumber(int arr[], int n){
    int xo = arr[0];
    for (int i = 1; i < n; i++)
        xo ^= arr[i];
    for (int i = 1; i <= n; i++)
        xo ^= i;

    //find rightmost setbit
    int setBit =   xo & ~(xo-1);
    
    //Now divide array in two section, one has setBit and other don't.
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]&setBit)
            x ^= arr[i];
        else
            y ^= arr[i];        
    }

    for (int i = 1; i <=n; i++)
    {
        if(i&setBit)
            x ^= i;
        else
            y ^= i;
    }

    // x & y are repeative and missing number but don't know which is missing or ..(for that you can run one loop over arr)
    cout << x << " and " << y;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    findMissingNumber(arr, n);
    return 0;
}