#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3;

bool isPossible(int val, int n, int k, int a[]){
    long long cont = 0;
    for(int i = 1; i <= n; i++) //filling the tower
        cont += min(val, a[i]); //val limits the length of the tower
    return cont <= 1LL * n * k;
} 


int maxNumOfGroups(int a[], int n, int k, int sum){
    int ans = 0, right = sum/k, left = 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(isPossible(mid,n,k,a)){
            ans = mid;
            left = mid+1;
        } else right = mid -1;
    }
    return ans;
}

int main () {
    int n,k, a[Nmax],sum=0;
    cin>>n>>k;
    for(int i=1; i <= n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<maxNumOfGroups(a,n,k,sum)<<endl;
    return 0;
}