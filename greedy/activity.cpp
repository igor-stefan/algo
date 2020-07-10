#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

struct activity{
    int start, finish;
    bool operator< (const activity& x) const{
        return finish < x.finish;
    }
};

int solveActivity(activity a[], int n){
    sort(a + 1, a + n + 1);
    int ans = 0, currFinish = -1;
    for(int j = 1; j <= n; j++){
        if(currFinish < a[j].start){
            ans++;
            currFinish = a[j].finish;
        }
    }
    return ans;
}

int main () {
    int n;
    activity a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].start >> a[i].finish;
    cout << solveActivity(a, n) << endl;

    return 0;
}