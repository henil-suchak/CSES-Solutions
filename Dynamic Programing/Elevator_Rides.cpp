#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, maxWt;
    cin >> n >> maxWt;
    vector<int> personWt(n);
    for (int i = 0; i < n; i++) cin >> personWt[i];

    sort(personWt.begin(), personWt.end());

    int ans = 0;
    int left = 0, right = n - 1;

    while (left <= right) {
        if (personWt[left] + personWt[right] <= maxWt) {
            left++;   // pair lightest
            right--;  // with heaviest
        } else {
            right--;  // heaviest alone
        }
        ans++;
    }

    cout << ans << "\n";
    return 0;
}