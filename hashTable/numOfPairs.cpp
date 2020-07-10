#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

int solve (int a[], int n, int S){
    int ans = 0;
    unordered_map <int, int> myMap;
    for(int j = 1; j <= n; j++){ 
        ans += myMap[S - a[j]]; //if (S - actual value) = a[i] that exists, then add to the answer because they make a pair  
        myMap[a[j]]++; //storing how many times my actual value appeared
    }
    return ans;
}

int main () {
    int n, S, a[Nmax];
    cin >> n >> S;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve(a,n, S) << endl; 

    return 0;
}