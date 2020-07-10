#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

int maxSumLeft(int a[], int left, int mid){
    int ans = a[mid], sum = 0;
    for(int lp = mid; lp >= left; lp--){
        sum += a[lp];
        ans = max(ans, sum);
    }
    return ans;
}

int maxSumRight(int a[], int mid, int right){
    int ans = a[mid+1], sum = 0;
    for(int rp = mid + 1; rp <= right; rp++){
        sum += a[rp];
        ans = max(ans, sum);
    }
    return ans;
}

int maxSumSubarray(int a[], int left, int right){
    if(left == right)
        return a[left];
    int mid = (left + right) / 2;
    int ans = max(maxSumSubarray(a, left, mid),
                  maxSumSubarray(a,mid + 1, right));
    return max(ans, maxSumLeft(a, left, mid) + 
                    maxSumRight(a,mid, right));
}

int main () {
    int n, a[Nmax];
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    cout << maxSumSubarray(a,1,n) << endl;
    return 0;
}