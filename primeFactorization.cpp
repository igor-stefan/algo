#include <bits/stdc++.h>

using namespace std;

int factors[100], expo[100], nOfFactors;

// This function has time complexity of O(n)
void primeFactorization(int n){
    if(n==1){
        factors[++nOfFactors] = 2;
        expo[nOfFactors] = 0;
        return;
    }
    int d=2; //initial prime number which will increase by 1 every step of while
    while(n>1){
        int k=0; //counter of how many divisions can be done
        while(n%d == 0){ //while is possible divide n by d
            n/=d;
            k++;
        }
        if(k>0){
            factors[++nOfFactors]=d;
            expo[nOfFactors]=k; 
        }
    d++;
    }
}

//This function has time complexity of O(sqrt n)
void fastPrimeFactorization(int n){
    if(n==1){
        factors[++nOfFactors] = 2;
        expo[nOfFactors] = 0;
        return;
    }
    int d=2; 
    while(1LL * d * d<=n and n>1){
        int k=0;
        while(n%d == 0){ //or d <= sqrt(n)
            n/=d;
            k++;
        }
        if(k>0){
            factors[++nOfFactors]=d;
            expo[nOfFactors]=k; 
        }
    d++;
    }
    if(n>1){  //because of d <= sqrt n test
        factors[++nOfFactors]=n;
        expo[nOfFactors]=1;
    }
}

int main(){
    int a=0;
    cin>>a;
    cout<<"a = "<<a<<endl;
    fastPrimeFactorization(a);
    for(int i=1;i<=nOfFactors;i++){
        cout<<factors[i]<<"^"<<expo[i];
        if(i<nOfFactors) cout<<" + ";
    }
    cout<<endl;
    return 0;
}