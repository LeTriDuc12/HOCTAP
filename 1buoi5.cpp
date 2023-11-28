#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    cout << solution.minCost(s) << endl;
    return 0;
}
