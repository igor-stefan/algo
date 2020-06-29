#include <bits/stdc++.h>

using namespace std;

int fastExpo(int a, long long n, int MOD){
    if(n==0) return 1;
    //(a^n) % MOD
    if(n%2 == 0) return fastExpo((1LL*a*a)%MOD,n/2,MOD);
    return 1LL * a * fastExpo(a,n-1,MOD) % MOD;
}

int main(){
    cout<<fastExpo(2,10,1000000007)<<endl;
    return 0;
}