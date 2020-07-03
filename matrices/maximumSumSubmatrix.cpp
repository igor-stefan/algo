#include<bits/stdc++.h>

using namespace std;

const int Nmax = 1e2;
const int Mmax = 1e2;

int a[Nmax][Mmax];
long long UpSum[Nmax][Mmax]; //Upsum[i][j] = a[1][j] + a[2][j] + ... +a[iMax][j]
//Upsum[i][j] = Upsum[i-1][j] + Upsum[i][j]; -> vector wich guards the actual sum of column till row i;

long long maxSumSubArray(long long a[], int n, int &c1, int &c2){
    long long ans=a[1], sum=0; 
    for(int i=1; i<=n; i++){
        sum+=a[i];
        if(sum>ans){
            ans=sum;
            c2=i;
        }
        if(ans<0){
            sum=0;
            c1=i;
        }
    }
    return ans;
}

long long maxSumSubmatrix(int n, int m, int &l1, int &c1, int &l2, int &c2){
    for(int i=1; i<=n; i++ ){
        for(int j=1; j<=n; j++){
            UpSum[i][j] = UpSum[i-1][j] + a[i][j]; 
        }
    }
    long long V[Mmax]; //will be the vector of sum of every column
    long long ans = a[1][1];
    for(int r1=1; r1<=n; r1++){ //row 1 and row 2 to pass trough all submatrices
        for(int r2=r1; r2<=n; r2++){
            for(int actual_col=1; actual_col<=m; actual_col++){
                V[actual_col]= UpSum[r2][actual_col] - UpSum[r1-1][actual_col];
            }
            long long actual_max_sum = maxSumSubArray(V,m,c1,c2); 
             //with vector ready, just take the maxSumSubarray possible
            if(actual_max_sum>ans){
                ans=actual_max_sum;
                l1=r1;
                l2=r2;
            }
        }
    }
    return ans;
}
int main() {
    int n,m,l1 = 0,c1 = 0,l2 = 0,c2 = 0;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    cout<<maxSumSubmatrix(n,m,l1,c1,l2,c2)<<"\nrow: "<<l1<<" col: "<<c1<<
    "\nrow: "<<l2<<" col: "<<c2<<endl;
    return 0;
}