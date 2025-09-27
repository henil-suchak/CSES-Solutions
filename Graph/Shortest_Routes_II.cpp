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
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> queries(q);
    vector<vector<long long> > graph(n+1,vector<long long>(n+1,LLONG_MAX));
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0; 
    for(int i=0;i<m;i++){
        int x,y;
        long long c;
        cin>>x>>y>>c;
        graph[x][y]=min(graph[x][y],c);
        graph[y][x]=min(graph[y][x],c);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][k]<LLONG_MAX && graph[k][j]<LLONG_MAX){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << graph[a][b] << "\n";
    }
}