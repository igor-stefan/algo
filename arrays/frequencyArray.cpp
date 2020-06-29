#include <bits/stdc++.h>

using namespace std;

//how many distinct elements are in an array ? --> O(n)
//frequency of each element ? --> O(1)

const int Nmax=1e5+5;

int fr[Nmax];

int numberOfDistinctValues(int arr[], int n){
    int cont = 0;
    for (int i=0;i<n;i++){
        if(fr[arr[i]]==0)
        cont++;
    fr[arr[i]]++;
    }
    return cont;
}

int main() {
    int n, array[Nmax], a=0;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>array[i];
    }
    a=numberOfDistinctValues(array,n);
    cout<<"numberOfDistinctValues = "<< a <<endl;
    for(int i=0; i<n;i++){
        cout << array[i] << "--> "<< fr[array[i]];
        if(fr[array[i]]>1) cout << " times" << endl; 
        else cout << " time" << endl;
    }
    return 0;
}