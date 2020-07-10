#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e4 + 3;
int numberOfRemainder[N_MAX]; //number that has certain remainder

void findNumbers(int number){
    int currentRemainder = 0;
    for(int i = 1; i <= number; i++){ //try i times until n
        currentRemainder = (currentRemainder * 10 + 1) % number;
        if(currentRemainder % number == 0){
            for(int j = 1; j <= i; j++) cout << "1";
            return;
        }
        if(numberOfRemainder[currentRemainder] != 0){ //if found 2 equal remainders
            for(int j = 1; j <= i - numberOfRemainder[currentRemainder]; j++) 
                cout << "1"; //show 1 j-i times
            for(int j = 1; j <= numberOfRemainder[currentRemainder]; j++) 
                cout << "0"; //show 0 i times
            return;
        }
        numberOfRemainder[currentRemainder] = i; //receives the number of 1's that has the current remainder
    }
}

int main(){
    int n;
    cin >> n;
    findNumbers(n); 
    cout << endl;
    return 0;
}