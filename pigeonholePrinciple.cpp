#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 13;
int frequencyOfRemainder[N_MAX];

void findNumbers(int number){
    int currentRemainder = 0;
    for(int i=1;i<=number;i++){ //try i times until n
        currentRemainder=(currentRemainder*10+1)%number;
        if(currentRemainder%number==0){
            for(int j=1;j<=i;j++) cout<<"1";
            return;
        }
        if(frequencyOfRemainder[currentRemainder]!=0){
            for(int j=1;j<=i-frequencyOfRemainder[currentRemainder];j++) cout<<"1";
            for(int j=1;j<=frequencyOfRemainder[currentRemainder];j++) cout<<"0";
            return;
        }
        frequencyOfRemainder[currentRemainder]=i; //or frequencyOfRemainder[currentRemainder]++
    }
}

int main(){
    findNumbers(N_MAX);
    cout<<endl;
    return 0;
}