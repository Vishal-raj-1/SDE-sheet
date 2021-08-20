#include<iostream>
using namespace std;

double pow(double m, int n){
    double ans = 1.0;
    for(int i=1; i<= n; i++)
        ans *= m;
    return ans;
}
double getNthRoot(int n, int m){
    double low = 1, high = m, eps = 1e-6;

    while(high - low > eps){
        double mid = low + (high-low)/2.0;
        if(pow(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    return high;//or low both of them will give your ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    cout << getNthRoot(n, m);
    return 0;
}