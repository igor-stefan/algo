#include <bits/stdc++.h>

using namespace std;

const int NMax = 1e5 + 2;

vector <int> findSum1(vector <int> nums, int S){
    int n = nums.size();
    unordered_set <int> mySums;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            for(int k = j; k < n; k++)
                mySums.insert(nums[i] + nums[j] + nums[k]);
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            for(int k = j; k < n; k++)
                if(mySums.find(S - (nums[i] + nums[j] + nums[k])) != mySums.end()){
                    for(int i1 = 0; i1 < n; i1++)
                        for(int j1 = i1; j1 < n; j1++)
                            for(int k1 = j1; k1 < n; k1++)
                                if(nums[i1] + nums[j1] + nums[k1] == S - (nums[i] + nums[j] + nums[k]))
                                return { nums[i], nums[j], nums[k],
                                        nums[i1], nums[j1], nums[k1]};
                }
    return {-1};
}

vector <int> findSum2(vector <int> nums, int S){
    int n = nums.size();
    unordered_map <int, vector <int>> mySums;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            for(int k = j; k < n; k++)
                mySums[nums[i] + nums[j] + nums[k]] = {i, j, k};
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            for(int k = j; k < n; k++)
                if(mySums.find(S - (nums[i] + nums[j] + nums[k])) != mySums.end()){
                    vector <int> v = mySums[S - (nums[i] + nums[j] + nums[k])];
                    return { nums[i], nums[j], nums[k],
                                nums[v[0]], nums[v[1]], nums[v[2]] };

                }
    return {-1};
}

int main() {
    int n, temp, S;
    vector <int> a;
    cin >> n >> S;
    for (int i = 1; i <= n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    vector <int> ans1 = findSum1(a,S), ans2 = findSum2(a,S);
    for (auto& x: ans1)
        cout << x << " ";
    cout << endl;
    for (auto& x: ans2)
        cout << x << " ";
    cout << endl;
    return 0;
}