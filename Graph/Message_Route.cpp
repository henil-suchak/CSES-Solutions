#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include<queue>
#include <climits>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x;
        cin>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    int result=INT_MAX;
    vector<bool> visited(n+1,false);
    bool flag=true;
    vector<int> parent(n+1);
    while(!q.empty()){
        auto[u,nodes]=q.front();
        q.pop();
        if(u==n){
            result=min(result,nodes);
            flag=false;
            break;
        }

       
        for(int v:graph[u]){
            
            if(!visited[v]){
                visited[v]=true;
                parent[v]=u;
                q.push(make_pair(v,nodes+1));
            }
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    for(int x=n;x!=1;x=parent[x]){
        ans.push_back(x);
    }
    ans.push_back(1);
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
    }
    return 0;
}