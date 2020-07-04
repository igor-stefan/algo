#include <bits/stdc++.h>

using namespace std;

void fillLeftVector(vector<int>& left, vector<int> heights){
    stack<int> st;
    for(int i = heights.size() - 1; i >= 0; i--){
        while(!st.empty() && heights[st.top()] > heights[i]){
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void fillRightVector(vector<int>& right, vector<int> heights){
    stack<int> st;
    for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

long long largestRetangularArea(vector<int> heights){
    int n = heights.size();
    vector<int> left(n, -1), right(n, n);
    fillLeftVector(left, heights);
    fillRightVector(right, heights);
    long long ans = 0;
    for(int k = 0; k < n; k++){
        ans = max(ans, (right[k]-left[k]-1)*heights[k]*1LL);
    }
    return ans;
}

int main () {
    vector<int> heights;
    int n, temp;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin >> temp;
        heights.push_back(temp);
    }
    cout << largestRetangularArea(heights) << endl; 
    return 0;
}