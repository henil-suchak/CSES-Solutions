#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include<unordered_set>
using namespace std;
int find(int x,vector<int>& parent){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x],parent);
}
void unionNodes(int u,int v,vector<int>& parent){
    int pu=find(u,parent);
    int pv=find(v,parent);
    if(pu!=pv){
        parent[pv]=pu;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    vector<vector<int> > edges(m,vector<int>(2,0));
    for(int i=0;i<m;i++){
        cin>>edges[i][0];
        cin>>edges[i][1];
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        unionNodes(edges[i][0],edges[i][1],parent);
    }
    for(int i=1;i<=n;i++){
        find(i,parent);
    }
    unordered_set<int> s;
    for(int i=1;i<=n;i++){
        if(!s.count(parent[i])){
            ans.push_back(parent[i]);
            s.insert(parent[i]);
        }
    }
    
    // cout<<endl<<endl;
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}