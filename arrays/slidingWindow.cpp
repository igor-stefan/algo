#include <bits/stdc++.h>

using namespace std;
//given an array of natural numbers find the longest subarray with at most k distinct numbers

const int Nmax = 1e5+5;
int fr[Nmax];


int slidingWindow(int a[], int n, int k, int &initial, int &final){
    int ans = 0, cont = 0, Right;
    for(Right=1; Right<=n; Right++){
        if(++fr[a[Right]] == 1)
            cont++;
        if(cont > k)
            break;
    }
    if(cont <= k)
        return n;
    if(--fr[a[Right--]] == 0)
        cont--;
    for(int Left = 2; Left <= n; Left++){
        if(--fr[a[Left-1]] == 0)
            cont--;
        while(Right < n){
            if(++fr[a[++Right]] == 1)
                cont++;
            if(cont>k)
                break;
        }
        if(cont <= k)
            return max(ans,n-Left+1);
        if(--fr[a[Right--]] == 0)
            cont--;
        if(Right-Left+1 > ans){
            ans = Right-Left+1;
            initial = Left;
            final = Right;
        }
    }
    return ans;
}
int main() {
    int n, arr[Nmax],k=2;
    cin>>n;
    int initial = 1, final = n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<slidingWindow(arr, n, k, initial, final)<<" -> ["
    <<initial<<","<<final<<"]"<<endl;
    return 0;
}