#include <iostream>
#include <algorithm> // For std::min and std::max

int main() {
    // Fast I/O is good practice
    std::ios_base::sync_with_stdio(false);
    std::cin::tie(NULL);

    long long t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;

        // A solution exists if and only if both conditions are met:
        // 1. The total sum is divisible by 3.
        // 2. The larger pile is not more than twice the smaller one.
        if ((a + b) % 3 == 0 && std::max(a, b) <= 2 * std::min(a, b)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}