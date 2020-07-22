#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 * 5 + 2;

int dp[Nmax][Nmax], a[Nmax], b[Nmax];

void reconstruct(int i, int j){
    if(i == 0 || j == 0)
        return;
    if(a[i] == b[j]){
        reconstruct(i - 1, j - 1);
        cout << a[i] << " ";
    }else {
        if(dp[i-1][j] > dp[i][j-1])
            reconstruct(i - 1, j);
        else
            reconstruct(i, j - 1);
    }
    
}

int lcs(int n, int m){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[n][m];
}

int main () {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
    cout << lcs(n, m) << endl;
    reconstruct(n, m);
    cout << "\n";
    return 0;
}