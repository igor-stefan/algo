#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5+5;
int fr[Nmax];

int slidingWindow(int a[], int n, int k){
    int ans = 0, cnt = 0, Right;
    for(Right=1; Right<=n; Right++){
        if(++fr[a[Right]] == 1) cnt++;
        if(cnt > k) 
            break; 
    }
    if(cnt<=k) return n;
    if(--fr[a[Right--]] == 0)
        cnt--;
    for(int left=2; left<=n; left++){
        if(--fr[a[left-1]] == 0)
            cnt--;
        while(Right < n){
            if(++fr[a[++Right]] == 1)
                cnt++;
            if(cnt>k)
                break;
        }
        if(cnt<=k) return max(ans, n - left + 1);
        if(--fr[a[Right--]] == 0)
            cnt--;
        ans=max(ans, Right - left + 1);
    }
    return ans;
}

int main() {
    int n, arr[Nmax],k=3;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<slidingWindow(arr,n,k)<<endl;
    return 0;
}