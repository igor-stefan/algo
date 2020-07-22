#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 * 2 + 5;
int dp[Nmax], pred[Nmax];


void reconstructDp(int i, int pred[]){
    vector<int> path = {i};
    int actual_index = i;
    while(pred[actual_index] != -1){
        actual_index = pred[actual_index];
        path.push_back(actual_index);
    }
    reverse(path.begin(), path.end());
    for(auto& x: path)
        cout << x << " ";
    cout << "\n";
}

void dP(int a[], int n){
    map<int, int> maxValue;
    int ans = 1, index = 1;
    pred[0] = -1;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        pred[i] = -1;
        if(maxValue.find(a[i] - 1) != maxValue.end()){
            int j = maxValue[a[i] - 1];
            pred[i] = j;
            dp[i] += dp[j];
            if(ans < dp[i]){
                ans = dp[i];
                index = i;
            }
        }
        maxValue[a[i]] = i;
    }
    cout << ans << "\n";
    reconstructDp(index, pred);
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
