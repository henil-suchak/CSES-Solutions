#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long x;
vector<long long> w;
vector<pair<int,long long>> dp; 

pair<int,long long> solve(int mask) {
    if (mask == 0) return {1, 0}; 
    if (dp[mask].first != -1) return dp[mask];

    pair<int,long long> best = {n+1, 0}; 


    for (int p = 0; p < n; p++) {
        if (mask & (1 << p)) {
            int prevMask = mask ^ (1 << p);
            auto option = solve(prevMask);

            if (option.second + w[p] <= x) {

                option.second += w[p];
            } else {

                option.first += 1;
                option.second = w[p];
            }
            best = min(best, option); 
        }
    }
    return dp[mask] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    w.resize(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    dp.assign(1 << n, {-1, -1});
    cout << solve((1 << n) - 1).first << "\n";
    return 0;
}