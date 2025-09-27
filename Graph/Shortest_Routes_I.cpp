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
    int n,m;
    cin>>n>>m;

    vector<long long> cost(n+1,LLONG_MAX);
    cost[1]=0;
    vector<vector<pair<long long,long long>> > graph(n+1);
    for(int i=0;i<m;i++){
        long long x,y,c;
        cin>>x>>y>>c;
        graph[x].push_back(make_pair(y,c));
    }
    queue<pair<long long,long long> > q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        auto [u,currentDist]=q.front();
        q.pop();

        for(auto [v,c] :graph[u]){
            if(cost[v]>cost[u]+c){
                cost[v]=(cost[u]+c);
                q.push(make_pair(v,cost[v]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cost[i]<<" ";
    }
    return 0;
}