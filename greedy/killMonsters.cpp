#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

int killMonsters(int dmg[], int n, int k, int hp){
    priority_queue<int> kills; //pair <damage, pos>
    for(int i = 1; i <= n; i++){
       if(dmg[i] <= 0){
           hp += -dmg[i];
           continue;
       }
       hp -= dmg[i];
       kills.push(dmg[i]);
       while(hp <= 0 && k > 0 && !kills.empty()){
           hp += kills.top();
           kills.pop();
           k--;
       }
       if(hp == 0) return i;
       if(hp < 0) return i - 1;
    }
    return n;
}

int main(){
    int n, hp, k, a[Nmax];
    cin >> n >> k >> hp;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << killMonsters(a, n, k, hp) << endl;
    return 0;
}