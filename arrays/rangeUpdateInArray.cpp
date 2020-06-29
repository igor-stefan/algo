#include <bits/stdc++.h>

using namespace std;

const int nMAX = 1e5+5;

int arrayOfNumbers[nMAX], updateArray[nMAX], sumUpdateArray[nMAX];

//the array index starts from 1

void update(int x, int y, int val){ //O(1) per query
    updateArray[x] += val;
    updateArray[y+1] -= val;
}

void buildPartialSumArray(int n){ //number of elements this function is O(n)
    sumUpdateArray[1]=updateArray[1];
    for (int i=1;i<=n;i++){
        sumUpdateArray[i] = sumUpdateArray[i-1] + updateArray[i]; //partial sum
        arrayOfNumbers[i] += sumUpdateArray[i]; //updates the original array
    }

}
int main() {
    int totalNumbers,  nOfQueries, index=0;
    cin>>totalNumbers>>nOfQueries;
    for(int index=1;index<=totalNumbers;index++){
        cin>>arrayOfNumbers[index];
    }
    int tempX,tempY,tempVal; //for receive querie values
    for(int j=1;j<=nOfQueries;j++){
        cin>>tempX>>tempY>>tempVal;
        update(tempX,tempY,tempVal);
    }
    buildPartialSumArray(totalNumbers);
    for(int j=1;j<=totalNumbers;j++){
        cout<<arrayOfNumbers[j]<< " ";
    }
    cout<<endl;
    return 0;
}