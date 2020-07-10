#include <bits/stdc++.h>

using namespace std;

int numOfBoats(vector<int> a, int w, int b){
    int ans = 0, p=0; 
    priority_queue<pair<int,int>> pq;
    vector<bool> isTaken(a.size(), false);
    sort(a.begin(), a.end());
    for(int i = a.size()-1; i >= 0; i--){
        while(p < i && a[i] + a[p] <= w)
            pq.push({a[p], p++});
        if(isTaken[i])
            continue;
        while(!pq.empty() && a[i] - pq.top().first <= b){
            if(isTaken[pq.top().second] || a[i] == pq.top().first){
                pq.pop();
                continue;
            }
            isTaken[i] = isTaken[pq.top().second] = true;
            pq.pop();
            break;
        }       
        ans++;
        }
    return ans;
}


int main () {
    int n, temp, w, b;
    vector<int> a;
    cin >> n >> w >> b;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    cout << numOfBoats(a, w, b) << endl;
    return 0;
}