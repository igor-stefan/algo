#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

vector <int> minimumElementsKSubarray(int a[], int n, int k){
    deque <int> dq;
    vector <int> ans;
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        dq.push_back(i);
        if(i >= k)
            ans.push_back(a[dq.front()]);
    }
    return ans;   
}


int main() {
    int n, k, a[Nmax];
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for (auto x: minimumElementsKSubarray(a, n, k))
        cout << x << " ";
    cout << "\n";
    return 0;
}