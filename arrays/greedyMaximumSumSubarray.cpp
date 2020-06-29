#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5+5;
//array indexes starts from 1

long long maxSumSubarray(int a[], int n, int &initial, int &final){
    int ans=a[1], sum=0;
    //takes elements one by one adding them;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>ans){
            ans=sum;
            final=i;
        }
        if(sum<0){
            sum=0;
            initial=i;
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