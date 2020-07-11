#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3;

int lis(int a[], int n){
    int ans = 0, k = 0, dp[Nmax] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i-1; j++){ //calculates the max lis until i-1
            if(a[j] < a[i]) //is a valid lis if the last element is less than i element
                k = max(k, dp[j]); //take the max in each iteration        
        }
        dp[i] = 1 + k; //recursion relation
        //the lis of i is 1 + lis(n - 1) which the last element of that lis is less than element i
    }
    for(int i = 1; i <= n; i++) //takes the value of max lis in array
        ans = max(ans, dp[i]); 
    return ans;
}

int main () {
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << lis(a, n) << endl;
    return 0;
}