#include <bits/stdc++.h>

using namespace std;


int numOfPlatforms(vector<pair<double, int>> events){
    int ans = 0, freePlatforms = 0;
    sort(events.begin(), events.end());
    for(auto& j: events){
        if(j.second){
            if(freePlatforms > 0)
                freePlatforms--;
            else ans++;
        }
        else freePlatforms++;
    }
    return ans;
}

int main () {
    int n;
    double arrival, departure;
    cin >> n;
    vector<pair <double, int>> events;
    for(int i = 1; i <= n; i++){
        cin >> arrival >> departure;
        events.push_back(make_pair(arrival, 1));
        events.push_back(make_pair(departure, 0));
    }
    cout << numOfPlatforms(events) << endl;
    return 0;
}