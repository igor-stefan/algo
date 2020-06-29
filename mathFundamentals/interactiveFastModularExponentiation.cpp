#include <bits/stdc++.h>

using namespace std;

int fastExpo(int a, long long n, int MOD){ //number, power, mod
    // --> (a^n) % MOD
    int ans = 1;
    while(n>=1){
        if(n%2 == 0){ //if n is even
            n/=2;
            a=((1LL*a*a)%MOD);
        }else{ //if n is odd
            n-=1;
            ans=((1LL*ans*a)%MOD);
        }
    }
    return ans;
    }

int main(){
    cout<<fastExpo(10,1300000,1e9+7)<<endl;
    return 0;
}