#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 2;
const int Gmax = 12;

int dp[Nmax][Gmax];

int knapsack(int w[], int v[], int n, int G){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= G; j++){
            dp[i][j] = dp[i - 1][j];
            if(w[i] <= j)
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
        }
    int ans = 0;
    for(int j = 0; j <= G; j++)
        ans = max(ans, dp[n][j]);
    return ans;
}



int main () {
    int n, G, w[Nmax], v[Nmax];
    cin >> n >> G;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << knapsack(w, v, n, G) << endl;

    return 0;
}