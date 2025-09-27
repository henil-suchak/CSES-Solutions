#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
vector<vector<pair<int,int>>> parent;
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
string moves = "UDLR";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vis.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));
    pair<int,int> A, B;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') A = {i,j};
            if (grid[i][j] == 'B') B = {i,j};
        }
    queue<pair<int,int>> q;
    q.push(A);
    vis[A.first][A.second] = true;
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k].first, ny = y + dir[k].second;
            if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = true;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }
    if (!vis[B.first][B.second]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<char> path;
    pair<int,int> cur = B;
    while (cur != A) {
        auto p = parent[cur.first][cur.second];
        if (p.first == cur.first-1) path.push_back('D');
        else if (p.first == cur.first+1) path.push_back('U');
        else if (p.second == cur.second-1) path.push_back('R');
        else if (p.second == cur.second+1) path.push_back('L');
        cur = p;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (char c : path) cout << c;
    cout << "\n";
}