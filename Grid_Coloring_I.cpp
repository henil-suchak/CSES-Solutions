#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<string> result;
string letters = "ABCD";
bool solved = false;

// Check if we can place character c at cell (i,j)
bool canPlace(int i, int j, char c) {
    if (c == grid[i][j]) return false; // must change
    if (i > 0 && result[i-1][j] == c) return false;
    if (j > 0 && result[i][j-1] == c) return false;
    return true;
}

// Recursive function to fill grid
void dfs(int i, int j) {
    if (solved) return; // stop if solution is already found
    if (i == n) {
        // reached end
        solved = true;
        return;
    }

    int ni = (j + 1 == m) ? i + 1 : i;
    int nj = (j + 1 == m) ? 0 : j + 1;

    for (char c : letters) {
        if (canPlace(i, j, c)) {
            result[i][j] = c;
            dfs(ni, nj);
            if (solved) return; // stop recursion if solution found
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    result.resize(n, string(m, ' '));
    for (int i = 0; i < n; i++) cin >> grid[i];

    dfs(0, 0);

    if (solved) {
        for (auto &row : result) cout << row << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}