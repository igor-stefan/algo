#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5+5;
//array indexes from 1 to n

long long maxSumSubarray(int a[], int n, int &initial, int &final){
    long long s[Nmax], ans = a[1], minSum = 0;
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+a[i]; //build partial sum array
    }
    for(int j=1;j<=n;j++){
        if(s[j]-minSum > ans){
            ans=s[j]-minSum;
            final=j;
        }
        if(s[j]<minSum){
            minSum=s[j];
            initial=j;
        }
    }
    initial+=1;
    return ans;
}

int main() {
    int n=0, array[Nmax];
    cin>>n;
    int initial=1, final=n;
    for(int i=1; i<=n; i++){
        cin>>array[i];
    }
    cout<<"Max Sum Subarray = "<<maxSumSubarray(array,n,initial,final)<<" ["<<initial<<","<<final<<"]"<<endl;
    return 0;
}