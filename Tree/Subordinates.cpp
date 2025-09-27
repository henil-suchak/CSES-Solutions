#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>

using namespace std;
int helper(int i,vector<vector<int> >& tree,vector<int>& ans){
    if(tree[i].size()==0){
        return 1;
    }
    for(int v:tree[i]){
        ans[i]+=helper(v,tree,ans);
    }
    return ans[i]+1;
}
int main(){
    int n;
    cin>>n;

    vector<int> ip(n+1);
    ip[1]=1;
    for(int i=2;i<=n;i++){
        cin>>ip[i];
    }
    vector<vector<int> > tree(n+1);
    for(int i=2;i<=n;i++){
        tree[ip[i]].push_back(i);
    }
    vector<int> ans(n+1,0);
    helper(1,tree,ans);
    for(int i=1;i<ans.size();i++) cout<<ans[i]<<" ";
}