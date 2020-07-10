#include <bits/stdc++.h>

using namespace std;

const int maxContestDuration = 240;

bool isPossible(int nOfQuestions, int minutes){
    int minutesRemaining = maxContestDuration - minutes;
    int timeOfQuestions = 0;
        for(int i=1; i <= nOfQuestions; i++)
            timeOfQuestions += i*5;
    if(timeOfQuestions <= minutesRemaining) return true;
    return false;
}
int bSearch(int n, int k){
    int ans = 0, right = n, left = 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(isPossible(mid,k)){
            ans = mid;
            left = mid+1;
        }
        else right = mid - 1;
    }
    return ans;
}

int main () {
    int n, k;
    cin >> n >> k;
    cout << bSearch(n,k) << endl;
    return 0;
}