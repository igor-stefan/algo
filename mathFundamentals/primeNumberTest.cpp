#include <bits/stdc++.h>

using namespace std;

//This function has time complexity of O(n)
bool bruteForce_isPrimeNumber(int n){
    if(n==0 || n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

//This function has time complexity of O(sqrt n)
bool byDefinition_isPrimeNumber(int n){
    if(n==0 || n==1) return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n=0;
    cin>>n;
    if(byDefinition_isPrimeNumber(n)) cout<<"Yes, "<<n<<" is a prime number"<<endl;
    else cout<<"No, "<<n<<" isn't a prime number"<<endl;
    return 0;
}