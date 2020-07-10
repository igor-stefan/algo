#include <bits/stdc++.h>

using namespace std;

long long connectRopes(vector <int> myVector){
    long long ans = 0;
    priority_queue<int> pq;
    for(auto x: myVector)
        pq.push(-x); //transform the pq in a min heap
    for(int step = 1; step < myVector.size(); step++){ //the number of steps is the length of the vector
        int fmin = -pq.top(); //take the min value and change signal
        pq.pop(); //pop from the pq
        int smin = -pq.top(); //take the next, now new min value from the heap (or pq)
        pq.pop(); //pop it
        ans += (fmin + smin); //connect the rope in the ans
        pq.push(-(fmin + smin)); //add the new rope in the pq with signal changed
    }
    return ans;
}

int main () {
    int temp, n;
    vector <int> a;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    cout << connectRopes(a) << endl;
    return 0;
}