#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
vector<int> temp;
vector<int> ans;
bool dfs(int u, vector<bool> &visited, vector<vector<int>> &graph,vector<int>& parent)
{
    visited[u] = true;

    // cout << u << " " << endl;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            parent[v]=u;
            if (dfs(v, visited, graph, parent))
            {
                return true;
            }
        }else if(v!=u){
            int current=u;
            ans.push_back(v);
            while(current!=v){
                ans.push_back(current);
                current=parent[current];
            }
            ans.push_back(v);
            if(ans.size()>=4) {
                cout<<ans.size()<<endl;
                for(int i:ans) cout<<i<<" ";
                return true;
            }
            ans.clear();
        }
    }

    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
   
    vector<bool> visited(n + 1, false);

    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if (!visited[i] && dfs(i, visited,  graph ,parent))
        {
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}