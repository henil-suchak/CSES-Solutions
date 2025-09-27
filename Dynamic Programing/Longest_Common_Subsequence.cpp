#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This function is correct. No changes needed.
int helper(int l1, int l2, vector<int> &str1, vector<int> &str2, vector<vector<int> > &dp)
{
    if (l1 < 0 || l2 < 0)
        return 0;
    if (dp[l1][l2] != -1)
        return dp[l1][l2];
    if (str1[l1] == str2[l2])
    {
        return dp[l1][l2] = helper(l1 - 1, l2 - 1, str1, str2, dp) + 1;
    }
    return dp[l1][l2] = max(helper(l1 - 1, l2, str1, str2, dp), helper(l1, l2 - 1, str1, str2, dp));
}

int main()
{
    int l1, l2;
    cin >> l1 >> l2;
    vector<int> vec1(l1), vec2(l2);
    for (int i = 0; i < l1; i++)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < l2; i++)
    {
        cin >> vec2[i];
    }

    vector<vector<int> > dp(l1, vector<int>(l2, -1));
    cout << helper(l1 - 1, l2 - 1, vec1, vec2, dp) << endl;

    // --- CORRECTED PRINTING LOGIC ---

    // 1. Create a vector to store the sequence.
    vector<int> lcs_sequence;
    int i = l1 - 1;
    int j = l2 - 1;

    // 2. Loop with the CORRECT condition (>=).
    while (i >= 0 && j >= 0)
    {
        if (vec1[i] == vec2[j])
        {
            // 3. Add the CORRECT element (vec1[i]) to the vector.
            lcs_sequence.push_back(vec1[i]);
            i--;
            j--;
        }
        else if (i > 0 && dp[i - 1][j] > (j > 0 ? dp[i][j - 1] : 0) )
        {
            // Move up if the value from the top is greater.
            i--;
        }
        else
        {
            // Otherwise, move left.
            j--;
        }
    }

    // 4. Reverse the vector to get the correct order.
    reverse(lcs_sequence.begin(), lcs_sequence.end());

    // 5. Print the final result.
    
    for (int k = 0; k < lcs_sequence.size(); k++)
    {
        cout << lcs_sequence[k] << " ";
    }
    cout << endl;

    return 0;
}