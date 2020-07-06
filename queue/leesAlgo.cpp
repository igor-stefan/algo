#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3;
bool a[Nmax][Nmax];
int n, m, dist[Nmax][Nmax], dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};


int leeAlgo (pair <int, int> src, pair <int, int> dst){
    queue < pair <int, int> > q;
    dist[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty()){
        pair <int, int> cell = q.front();
        if(cell == dst)
            return dist[cell.first][cell.second] - 1;
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            if(a[cell.first + dx[dir]][cell.second + dy[dir]] == 1 and 
                dist[cell.first + dx[dir]][cell.second + dy[dir]] == 0){
                    dist[cell.first + dx[dir]][cell.second + dy[dir]] = dist[cell.first][cell.second] + 1;
                q.push(make_pair(cell.first + dx[dir], cell.second + dy[dir]));
                }
        }
    }
    return -1;
}

int main () {
    int xi, yi, xf, yf;
    cin >> n >> m >> xi >> yi >> xf >> yf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    cout << leeAlgo(make_pair(xi, yi), make_pair(xf, yf)) << endl;
    return 0;
}