#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>
#include <cmath>


using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long> > >graph(n+1);
    for(int i=0;i<m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }

    vector<vector<long long> > cost(n+1,vector<long long>(2,LLONG_MAX));
    cost[1][0]=0;
    cost[1][1]=0;
    priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long> > > q;
    q.push(make_tuple(0,1,1));//cost,node,bit

    while(!q.empty()){
        auto [costLocal,u,bit]=q.top();
        q.pop();
        if(u==n) break;
        if(costLocal>cost[u][bit]) continue;
        for(auto [v,wt]:graph[u]){
            if(bit && cost[v][0]>costLocal+floor(wt/2)){
                cost[v][0]=costLocal+floor(wt/2);
                q.push(make_tuple(costLocal+floor(wt/2),v,0));
            }
            if(cost[v][bit]>costLocal+wt){
                cost[v][bit]=wt+costLocal;
                q.push(make_tuple(costLocal+wt,v,bit));
            }
        }
    }
    cout<<min(cost[n][0],cost[n][1]);
    return 0;

}
