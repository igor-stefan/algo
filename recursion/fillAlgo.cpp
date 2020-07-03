// you are given a 2D grid map of '*' (land) and '#' (water). An island is formedby connecting
// ajacent land cells horizontally or vertically and is surrounding by water. 
// Find the number of islands and the max numbers of cells  of one island. 
#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3+5;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int vis[Nmax][Nmax], n, m;
char a[Nmax][Nmax];

bool isOk(int row, int col){ //verify cell
    if(row < 1 || row > n || col < 1 || col > m || a[row][col] == '#' || vis[row][col])
        return false;
    return true;
}

void fillAlgo(int row, int col, int& cellsCounter){ //fill the way as long as the cell is a valid one
    cellsCounter++;
    vis[row][col] = true;
    for(int dir = 0; dir < 4; dir++)
        if(isOk(row + dy[dir], col + dx[dir])) //verify four directions: up, right, down, left
            fillAlgo(row + dy[dir], col + dx[dir], cellsCounter);
}

int main () {
    int maxCellsCounter = 0, nOfIslands = 0;
    cin>>n>>m;
    cout<<n<<" "<<m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(isOk(i,j)){
            int cellsCounter = 0;
            cout<<"i: "<<i<<" j: "<<j<<endl;
            nOfIslands++;
            fillAlgo(i, j, cellsCounter);
            maxCellsCounter = max(maxCellsCounter, cellsCounter);
            }
        }

    cout<<nOfIslands<<" "<<maxCellsCounter<<endl;       
    
    return 0;
}