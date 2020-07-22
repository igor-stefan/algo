#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 * 2 + 5;
int dp[Nmax];


void reconstructDp(int i, int ans, int num, int a[]){
    if(i == 0) return;
    if(dp[i] == ans && a[i] == num){
        ans -= 1;
        num -= 1;
        reconstructDp(i - 1, ans, num, a);
        cout << i << " ";
    }else
        reconstructDp(i - 1, ans, num, a);
}

void dP(int a[], int n){
    map<int, int> maxValue;
    int ans = 1, index = 1;
    dp[1] = 1;
    maxValue[a[1]] = 1;
    for(int i = 2; i <= n; i++)
        if(a[i] - 1 == a[i - 1])
        {
            maxValue[a[i]] = i;
            dp[i] = 1 + dp[i - 1];
            if(ans < dp[i]){
                ans =  dp[i];
                index = i;
            }
        }else{
            maxValue[a[i]] = i;
            dp[i] = 1 + dp[maxValue[a[i] - 1]];
            if(ans < dp[i]){
                ans =  dp[i];
                index = i;
            }
        }
    cout << ans << "\n";
    reconstructDp(index, ans,a[index], a);
    cout << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dP(a,n);
    return 0;
}

// void bruteForce(int a[], int n){
// unordered_map <int, vector<int>> val;
//     int maxN = 0, ans = 1, index = 1;
//     for(int i = 1; i <= n; i++){
//         maxN = a[i];
//         val[i].push_back(i);
//         for(int j = i + 1; j <= n; j++){
//             if(a[j] != maxN + 1)
//                 continue;
//             else{
//                 maxN = a[j];
//                 val[i].push_back(j);
//                 if(ans < val[i].size()){
//                     index = i;
//                     ans = val[i].size();
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
//     for(int i = 0; i < ans; i++)
//         cout << val[index][i] << " ";
//     cout << "\n";
// }
