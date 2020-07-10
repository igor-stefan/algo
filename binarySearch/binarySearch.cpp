#include<bits/stdc++.h>

using namespace std;

//return the position of target value or -1 if it doesnt exist

int bSearch(int a[], int n, int target){
    int right = n, left = 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(a[mid] == target)
            return mid;
        if(a[mid] > target)
            right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int n,val;
    cin>>n>>val;
    int myArray[n];
    for(int i=1; i<=n; i++)
        cin >> myArray[i];
    cout << bSearch(myArray, n, val) << endl;
    return 0;
}