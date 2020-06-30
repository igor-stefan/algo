#include <bits/stdc++.h>

using namespace std;
//given an array of natural numbers find the longest subarray with at most k distinct numbers

const int Nmax = 1e5+5;
int fr[Nmax];


int slidingWindow(int a[], int n, int k, int &initial, int &final){
    int ans = 0, cont = 0, Right;
    for(Right=1; Right<=n; Right++){ //update right pointer
        if(++fr[a[Right]] == 1) //adds one in the frequency array and verify if it is a new element
            cont++; //if it is then cont++
        if(cont > k) //if cont greater than limit
            break;
    }
    if(cont <= k) //if the loop ended without break then all array is valid
        return n; //return the lenght of array
    if(--fr[a[Right--]] == 0) //else decrement one in frequency of number and in right pointer
        cont--; //verify if it was counted like new element and fix it
    for(int Left = 2; Left <= n; Left++){ //pointer left goes form 2 to lenght of array
        if(--fr[a[Left-1]] == 0) //decreases one in the frequency of the last element of left pointer
            cont--;  //if it was a new element, fixes it
        while(Right < n){ //increases the rigth pointer till length of array
            if(++fr[a[++Right]] == 1) //increases one in frequency of number
                cont++; //if it is a new element then cont++
            if(cont>k) //if cont is greater than limit
                break;
        }
        if(cont <= k) //if the loop ended withou break
            return max(ans,n-Left+1); //ans = max(ans, lenght of actual subarray)
        if(--fr[a[Right--]] == 0) //if ended with break decreases freqeuncy of element of right pointer and right pointer
            cont--; //if it was a new element fix it      
        if(Right-Left+1 > ans){ //verify if the actual lenght is greater than actual ans
            ans = Right-Left+1; 
            initial = Left; 
            final = Right;
        }
    }
    return ans;
}
int main() {
    int n, arr[Nmax],k=2;
    cin>>n;
    int initial = 1, final = n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<slidingWindow(arr, n, k, initial, final)<<" -> ["
    <<initial<<","<<final<<"]"<<endl;
    return 0;
}