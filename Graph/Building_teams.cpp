#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
bool dfs(int u, vector<bool> &visited, int cu, vector<vector<int>> &graph, vector<int> &color)
{

    visited[u] = true;
    color[u] = cu;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            if (dfs(v, visited, !cu, graph, color))
            {
                return true;
            }
        }
        else if (color[u]==color[v])
        {
            return true;
        }
    }
    // visited[u]=false;
    // color[u]=-1;
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
    vector<int> color(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, visited, 1, graph, color))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        if(color[i]==0){
            cout<<2<<" ";
        }else{
            cout<<1<<" ";
        }

    }
    return 0;
}