#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3-1e2*3;

int a[Nmax][Nmax], partialSumA[Nmax][Nmax];
//matrix a to receive updates partialSumA to build the partial sum matrix after updates in a
void update(int r1, int c1, int r2, int c2, int val){
    a[r1][c1]+=val;
    a[r1][c2+1]-=val;
    a[r2+1][c1]-=val;
    a[r2+1][c2+1]+=val;

}

void buildPartialSumMatrix(int arr[Nmax][Nmax], int myArray[Nmax][Nmax], int n , int m){
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            partialSumA[i][j] =  //build partial sum matrix
            partialSumA[i][j-1]+
            partialSumA[i-1][j]+
            arr[i][j]+
            -partialSumA[i-1][j-1];
            myArray[i][j]+=partialSumA[i][j];  //add the values to the original matrix
            if(myArray[i][j] < 10 && myArray[i][j] > -10){ //just check for pretty print
                cout<<"  "<<myArray[i][j]<<" "; 
            } else cout<<myArray[i][j]<<" ";   
        }
        cout<<"\n";
    }            
}

int main() {
    int n,m,u,myArray[Nmax][Nmax];
    cin>>n>>m>>u; //receives rows columns nOfUpdates
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>myArray[i][j];
    for(int x=0; x<u; x++){
        int tempR1, tempC1, tempR2, tempC2, tempVal;
        cin>>tempR1 >> tempC1 >> tempR2 >> tempC2 >> tempVal;
        update(tempR1, tempC1, tempR2, tempC2, tempVal); //apply the updates to matrix a
    }  
    buildPartialSumMatrix(a, myArray, n, m); //result of all updates
    return 0;
}