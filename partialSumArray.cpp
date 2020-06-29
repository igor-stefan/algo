#include <bits/stdc++.h>

using namespace std;

const int nMAX=1e5+5;

int partialSum[nMAX];

void buildPartialSum(int array[], int n){ //receives array with number and a limit index to build partial sum array
    partialSum[1]=array[1];
    for(int i=2;i<=n;i++){
        partialSum[i]=partialSum[i-1]+array[i];
    }
}

long long Query(int x, int y){
    return partialSum[y]-partialSum[x-1];
}

int main() {
    int n=0,index=0, array[nMAX];
    int q=0,x,y;
    vector< pair<int,int> > queries;
    //receive array and pair of queries(x,y)
    cin>>n>>q;
    while(n--){
        index++;
        cin>>array[index];
    }
    while(q--){
        cin>>x>>y;
        queries.push_back(make_pair(x,y));
    }
    buildPartialSum(array,index);

    for(int a=0;a<3;a++){
        cout<<a+1<<". query: ("<<queries[a].first<<","<<queries[a].second<<") = ";
        cout<<Query(queries[a].first,queries[a].second)<<endl;
    }

    return 0;
}
