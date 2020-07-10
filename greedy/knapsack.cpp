#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

struct obj{
    int w; //weight of object
    double vpu; //value per unit 
    bool operator< (const obj& x) const{ //operator for sort
        return vpu > x.vpu;
    }
};

int solve(obj a[], int n, int G){
    sort(a + 1, a + n + 1);
    double ans = 0;
    for(int i = 1; G > 0; i++){
        int q = min(a[i].w, G); //take the minimum between the weight of object and the lefting weight of knapsack
        ans += q * a[i].vpu; //the amount of value it can take is the weight available to be taken times the value per weight of object
        G -= q; //update the new knapsack available weight
    }
    return ans;
}

int main () {
    int n, G;
    obj a[Nmax];
    cin >> n >> G;
    for (int i = 1; i <= n; i++){
        int v, w;
        cin >> v >> w;
        a[i].w = w;
        a[i].vpu = (double) v/w;
    }
    cout << solve(a, n, G) << endl;

    return 0;
}