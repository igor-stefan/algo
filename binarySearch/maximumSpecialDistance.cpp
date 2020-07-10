#include <bits/stdc++.h>

using namespace std;

bool isValid(int dist, vector<pair<int, int>> points){
    int n = points.size();
    int p = -1, minY=INT_MAX, maxY=INT_MIN;
    for(int j = 0; j < n; j++){
        while(p+1 < j && abs(points[j].first - points[p+1].first) >= dist){
            p++;
            minY = min(minY, points[p].second);
            maxY = max(maxY, points[p].second);
        }
        if(p!= -1 && abs(minY - points[j].second) >= dist)
            return true;
        if(p != -1 && abs(maxY - points[j].second) >= dist)
            return true;
    }
    return false;
}

int bSearch(vector<pair<int, int>> points){
    int ans, mid, left=0, right=1e6;
    while(left <= right){
        mid = (left+right) / 2;
        if(isValid(mid,points)){
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}

int main() {
    int n;
    vector<pair<int, int>>points;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    sort(points.begin(), points.end());
    cout << bSearch(points) << endl;
    return 0;
}