#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 5;
int n,m;
int towerHeight[Nmax][Nmax];


void buildTowerArray(int a[][Nmax], int n, int m){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0)
                towerHeight[i][j] = 0;
            else
                towerHeight[i][j] = towerHeight[i-1][j] + 1;
        }
}

void fillLeftArray(int arr[], int heights[], int n){
    stack<int> st;
    for(int i = n; i >= 1; i--){
        while(!st.empty() && heights[st.top()] > heights[i]){
            arr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void fillRightArray(int arr[], int heights[], int n){
    stack<int> st;
    for(int i = 1; i <= n; i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            arr[st.top()]  = i;
            st.pop();
        }
        st.push(i);
    }
}

long long largestRectangleHistogram(int a[], int n){
    int left[n], right[n];
    for(int i = 1; i <= n; i++){
        //fill with values outside range because of exclusive count
        left[i] = 0; //first value before array starts
        right[i] = n+1; //values outside range
    }
    fillRightArray(right, a, n);
    fillLeftArray(left, a, n);
    long long ans = 0;
    for(int k = 1; k <= n; k++){
        ans = max(ans, ((right[k] - left[k]) - 1)*a[k]*1LL);
    }
    
    return ans;
}

long long maximumAreaRectangle(int a[][Nmax], int n, int m){
    long long ans = 0;
    buildTowerArray(a, n, m);
    for(int k = 1; k <= n; k++)
        ans = max(ans, largestRectangleHistogram(towerHeight[k], m));
    return ans;
}   

int main () {
    int a[Nmax][Nmax];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << maximumAreaRectangle(a, n, m) << endl;
    return 0;
}