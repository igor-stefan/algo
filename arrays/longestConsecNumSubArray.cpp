#include <bits/stdc++.h>

using namespace std;
//array indexes starts from 1

const int Nmax = 1e5+5;
bool fr[Nmax];

int longestConsecNumSubArray(int arr[], int n, int &initial, int &final){
    int ans=0;
    for (int left=1;left<=n;left++){ //loop the array
        int Min=arr[left],Max=arr[left]; //for every element it will be the min and the max
        for(int i=1; i<=n; i++) //turn the frequency arrray all false
            fr[i]=false;
        for(int right=left; right<=n; right++){ //pointer of right
            if(fr[arr[right]]) //if found a repetead value isn't necessary to continue looping, the subarray is invalid
                break;   
            fr[arr[right]] = true; //if isn't a repetead value, then is a new value
            Min=min(Min,arr[right]); //take the min till the actual value
            Max=max(Max,arr[right]); //take the max till the actual value
            if(Max - Min == right - left ){ //if the condition is satisfied
                if(Max-Min+1 > ans){ //verify if it is greater than actual ans
                    ans=Max-Min+1; //if it is update ans value
                    initial=left; //update the initial index of subarrray
                    final=right; //update the final index of subarrray
                }
            }
        }
    }
    return ans; 
}
int main() {
    int n, arr[Nmax];
    cin>>n;
    int initial=1,final=n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<"ans = "<<longestConsecNumSubArray(arr,n,initial,final)
    <<" --> "<<"["<<initial<<","<<final<<"]"<<endl;

    return 0;
}