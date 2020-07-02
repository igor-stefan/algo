#include<bits/stdc++.h>

using namespace std;

//return the position of target value or -1 if it doesnt exist
const int Nmax = 1e5+5;
int nOfRides(long long c, int n, int g[]){
    int cont = 1;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum+=g[i];
        if(sum <= c){
            continue;
        }
        else {
            cont++;
            sum=g[i];
        }
    }
    return cont;
}

long long bSearch(int n, int a[], int k, long long sumOfAllElements, long long maxWeightOfElement){
    int rides = 0;
    long long right = sumOfAllElements, left = maxWeightOfElement, ans = INT_MAX, mid;
    while(left <= right){
        mid = (left + right) / 2;
        rides = nOfRides(mid, n, a);
        if( rides <= k ){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

int main() {
    int n,k, weight[Nmax];
    long long sum = 0, maxWeightOfElement = INT_MIN;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>weight[i];
        if(maxWeightOfElement < weight[i])
            maxWeightOfElement = weight[i];
        sum+=weight[i];
    }
    cout << bSearch(n, weight, k, sum, maxWeightOfElement) << endl;
    return 0;
}