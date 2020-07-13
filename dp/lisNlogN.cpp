#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;
int dp[Nmax], minLast[Nmax];

int lis (int a[], int n){
    int len = 1; //initialize doing first iteration by hand
    dp[1] = 1;
    minLast[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] > minLast[len]){
            len++;
            dp[i] = len;
            minLast[len] = a[i];
        } else {
            int p = upper_bound(minLast + 1, minLast + len + 1, a[i]) - minLast;
            if(minLast[p - 1] == a[i]) p--;
            dp[i] = p;
            minLast[p] = a[i];
        }
    }
    return len;    
}
int main () {
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << lis(a, n) << endl;
    return 0;
}