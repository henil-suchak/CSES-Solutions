#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

struct Edge {
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};

const int MAXN = 505;
const int INF = numeric_limits<int>::max();

int N; 
vector<Edge> G[MAXN];
int levelArr[MAXN], iterArr[MAXN];

void add_edge(int from, int to, int cap) {
    G[from].push_back(Edge(to, cap, (int)G[to].size()));
    G[to].push_back(Edge(from, 0, (int)G[from].size() - 1));
}

void bfs_level(int s) {
    fill(levelArr, levelArr + N + 1, -1);
    queue<int> q;
    levelArr[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (const Edge &e : G[v]) {
            if (e.cap > 0 && levelArr[e.to] < 0) {
                levelArr[e.to] = levelArr[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs_flow(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iterArr[v]; i < (int)G[v].size(); ++i) {
        Edge &e = G[v][i];
        if (e.cap > 0 && levelArr[v] < levelArr[e.to]) {
            int d = dfs_flow(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        bfs_level(s);
        if (levelArr[t] < 0) return flow;
        fill(iterArr, iterArr + N + 1, 0);
        int f;
        while ((f = dfs_flow(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

// Extract one path by following edges with flow (reverse capacity > 0)
bool extract_path(int u, int t, vector<int>& path) {
    if (u == t) return true;
    for (Edge &e : G[u]) {
        Edge &revEdge = G[e.to][e.rev];
        if (revEdge.cap > 0) {  // means flow was sent u -> e.to
            // consume 1 unit of flow
            revEdge.cap -= 1;
            e.cap += 1;

            path.push_back(e.to);
            if (extract_path(e.to, t, path)) return true;

            // rollback if failed
            path.pop_back();
            revEdge.cap += 1;
            e.cap -= 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> N >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);  // unit capacity
    }

    int s = 1, t = N;
    int flow = max_flow(s, t);

    cout << flow << "\n";
    for (int i = 0; i < flow; i++) {
        vector<int> path;
        path.push_back(s);
        extract_path(s, t, path);
        cout << path.size() << "\n";
        for (int node : path) cout << node << " ";
        cout << "\n";
    }
    return 0;
}