#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 2;
const int Gmax = 12;

int dp[Nmax][Gmax];

void printItems(int ans, int n, int G, int w[], int v[]){
    for(int i = n; i > 0 && ans > 0; i--){
        if(ans == dp[i - 1][G])
            continue;
        else{
            cout << w[i] << " ";
            ans -= v[i]; 
			G -= w[i];            
        }
    }
    cout << "\n";
}

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
    int n, G, w[Nmax], v[Nmax], ans;
    cin >> n >> G;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    ans = knapsack(w, v, n, G);
    cout << ans << "\n";
    printItems(ans, n, G, w, v);
    return 0;
}