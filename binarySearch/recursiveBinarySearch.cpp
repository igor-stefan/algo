#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e4+2;

int recursiveBinarySearch(int a[], int n, int target, int left, int right ){
    int mid = (right+left) / 2;
    if(left > right) 
        return -1;
    if(a[mid] == target)
        return mid;
    if(target < a[mid])
        return recursiveBinarySearch(a, n, target, left, mid - 1);
    return recursiveBinarySearch(a, n, target, mid + 1, right);
}

int main () {
    int left, right, target, n, arr[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    left = 1; right = n; target = 17;
    cout << recursiveBinarySearch(arr, n, target, left, right) << endl;
    return 0;
}