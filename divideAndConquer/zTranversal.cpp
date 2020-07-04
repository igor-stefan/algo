#include <bits/stdc++.h>

using namespace std;

int zTransversal(int n, int x, int y){

    if(n == 0)
        return 1;
    if(x <= 1 << (n - 1)){ //verify if x is in the upper left or upper right square
        if(y <= (1 << (n-1))) //if its in the upper left
            return zTransversal(n-1, x, y);
    return (1 << (2*n - 2)) + zTransversal(n-1, x, y - (1 << (n-1))); //if it is in the upper bottom
    }

    if(y <= (1 << (n-1))) //then if x,y are in the bottom left
        return  2 * (1 << (2*n - 2)) + zTransversal(n-1, x - (1 << (n-1)), y);
    return 3 * (1 << (2*n - 2)) + zTransversal(n-1, x - (1 << (n-1)), y - (1 << (n-1))); //else x,y are in the bottom right
}

int main () {
    int n, x, y;
    cin >> n >> x >> y;
    cout << zTransversal(n, x, y) << endl;
    return 0;
}