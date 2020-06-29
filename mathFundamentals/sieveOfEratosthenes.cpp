#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100001;
bool numbers[Nmax];

//This function has time complexity of O(n log n)
void sieveOfEratosthenes(bool vectorOfNumbers[]){
    for(int i=2;i<Nmax;i++) vectorOfNumbers[i]=true;
    for(int i=2;i<(Nmax/2.0);i++){
        if(vectorOfNumbers[i]){
            for(int j=i*2;j<(Nmax);j+=i){
                vectorOfNumbers[j]=false;
            }
        }
    }
}
int main(){
    int cont=0;
    sieveOfEratosthenes(numbers);
    for(int x=0;x<Nmax;x++){
        if(numbers[x]){ cout<<x<<" "; ++cont;}
        if(cont>9){
            cout<<endl;
            cont=0;
        }
    }
    return 0;
}