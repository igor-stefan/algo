#include <bits/stdc++.h>

using namespace std;

int recursiveFib(int n){
    if(n < 2) return 1;
    return recursiveFib(n-1) + recursiveFib(n-2);
}

unsigned long long int dpFib(int n){
    vector<unsigned long long int> fib = {1, 1};
    for(int i = 2; i <= n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib[n];
}

int main () {
    int n;
    cin >> n;
    cout << recursiveFib(n) << endl;
    cout << dpFib(n) << endl;
    return 0;
}