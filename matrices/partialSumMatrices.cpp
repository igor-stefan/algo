#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3;
int partialSumMatrix[Nmax][Nmax];

void buildPartialSumMatrix(int arr[Nmax][Nmax], int n , int m){ //build O(n)
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            partialSumMatrix[i][j] = 
            partialSumMatrix[i][j-1]+
            partialSumMatrix[i-1][j]+
            arr[i][j]+
            -partialSumMatrix[i-1][j-1];  
        }
    }            
}

long long query(int l1, int c1, int l2, int c2){ //query O(1)
    return partialSumMatrix[l2][c2] - partialSumMatrix[l1-1][c2]-
            partialSumMatrix[l2][c1-1] + partialSumMatrix[l1-1][c1-1]; 
}
int main () {
    int n,m, arr[Nmax][Nmax];
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            cin>>arr[i][j];

    buildPartialSumMatrix(arr, n, m);
    cout<<"Partial SUM MATRIX: "<<endl;
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout<<partialSumMatrix[i][j]<<" ";
        }
        cout<<endl;
    }   
    cout<<"\n";
    cout<<"query = "<<query(3,1,4,4)<<endl; //example query

    return 0;
}