#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 1;
bool matrix[Nmax][Nmax];
int n, m, maxLength[Nmax][Nmax];

int maxSizedSquare(bool a[][Nmax], int n, int m){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            if(a[i][j] == false)
                maxLength[i][j] = 0;
            else maxLength[i][j] = min(maxLength[i-1][j],
                                min(maxLength[i][j-1], maxLength[i-1][j-1])) + 1;
            ans=max(ans,maxLength[i][j]);
        }
    }
    return ans;
}



int main () {
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> matrix[i][j];
    cout << maxSizedSquare(matrix, n, m) << endl;
    return 0;
}