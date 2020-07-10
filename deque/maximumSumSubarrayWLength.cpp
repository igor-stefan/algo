#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
int sum[Nmax];

int myFunc(int a[], int n, int A, int B){
    int ans = 0, minS = a[1];
    deque <int> dq;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    for(int right = 1; right <= n; right++){
        while(!dq.empty() and dq.front() < right-B)
            dq.pop_front();
        if(right >= A)
            cout << "ans = " << sum[right]-sum[dq.front()] <<"\n";
            ans = max(ans, sum[right]-sum[dq.front()]);
        while(!dq.empty() and sum[dq.back()] >= sum[right])
            dq.pop_back();
        dq.push_back(right);
    }
    return ans;
}

int main() {
    int n, v[Nmax], a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    cout << myFunc(v, n, a, b) << "\n";
    return 0;
}