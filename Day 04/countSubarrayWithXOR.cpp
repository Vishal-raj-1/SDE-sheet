#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubarrayWithGivenXOR(vector<int>&v, int m){
    int n = v.size();
    int XOR = 0, count = 0;
    unordered_map<int, int>mp;
    for (int i = 0; i < n; i++)
    {
        XOR ^= v[i];
        if(XOR == m)
            count++;
        
        if(mp.find(XOR^m) != mp.end())
            count += mp[XOR^m];
        
        mp[XOR]++;
    }
    return count;
}
int main(){
    int n, xr;
    cin >> n >> xr;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    cout << countSubarrayWithGivenXOR(v, xr);
    return 0;
}