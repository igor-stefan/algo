#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 * 7 + 2;
int dp[Nmax][Nmax]

int minimumEditDistance(string s1, string s2, int c1, int c2, int c3){
    //initialize dp matrix
    for(int i = 0; i <= s1.size(); i++)
        dp[i][0] = i * c2;
    for(int j = 0; j <= s2.size(); j++)
        dp[0][j] = j * c1;
    //start computing dp
    for(int i = 1; i <= s1.size(); i++)
        for(int j = 1; j <= s2.size(); j++){
            dp[i][j] = c1 + dp[i][j - 1]; //insertion
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + c2); //deletion
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + c3); //replacement
            if(s1[i - 1] == s2[j - 1])  //or take no actions
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    return dp[s1.size()][s2.size()];
}


int main() {
    int c1, c2, c3;
    string s1, s2;
    cin >> c1 >> c2 >> c3 >> s1 >> s2;
    cout << minimumEditDistance(s1, s2, c1, c2, c3) << endl;
    return 0;
}