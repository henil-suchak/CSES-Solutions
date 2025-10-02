#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long> > graphMatrix;
    for(int i=0;i<m;i++){
        long long x,y,c;
        cin>>x>>y>>c;
        graphMatrix.push_back({x,y,c});
    }
    vector<long long> distance(n+1,LLONG_MIN);
    distance[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=graphMatrix[j][0];
            int v=graphMatrix[j][1];
            int c=graphMatrix[j][2];
            if(distance[u]+c>distance[v]){
                distance[v]=distance[u]+c;
            }
        }
    }
    for(int i=0;i<m;i++){
        int u=graphMatrix[i][0];
            int v=graphMatrix[i][1];
            int c=graphMatrix[i][2];
            if(distance[u]+c>distance[v]){
                cout<<-1;
                return -1;
            }
    }
    cout<<distance[n];
    return 0;
}
