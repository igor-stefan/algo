#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
int b[Nmax];

void mergeArrays(int a[], int left, int mid, int right){
    int i = left; int j = mid+1; int p = 1;
    while(i <= mid and j <= right){
        if(a[i] <= a[j])
            b[p++] = a[i++];
        else b[p++] = a[j++];
    }
    while (i <= mid)
        b[p++] = a[i++];
    while (j <= right)
        b[p++] = a[j++];
    for(i = left; i <= right; i++)
        a[i] = b[i - left + 1];
}

void mergeSort(int a[], int left, int right){
    if(left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    mergeArrays(a, left, mid, right);
}


int main (){
    int n, a[Nmax];
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    mergeSort(a, 1, n);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout<<endl; 

    return 0;
}
