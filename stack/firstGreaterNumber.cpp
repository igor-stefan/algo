#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

void solveArray(int a[], int n, int ans[]){
    stack <int> S;
    for (int i = 1; i <= n; i++){
        while(!S.empty() && a[S.top()] < a[i]){
            ans[S.top()] = i;
            S.pop();
        }
        S.push(i);
    }
}

int main() {
    int n, a[Nmax], ans[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solveArray(a, n, ans);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}