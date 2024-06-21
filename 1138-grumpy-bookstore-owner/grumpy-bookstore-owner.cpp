class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int i, k = 0, ans = 0, n = c.size();

        vector<int> p(n, 0); 
        vector<vector<int>> dp(n, {2, 0}); 

        k = c[0]; 
        p[0] = g[0] * c[0]; 
        dp[0][0] = p[0]; 
        for (i = 1; i < n; i++) {
            k += c[i]; 

            if (g[i] == 1)
                p[i] = c[i] + p[i - 1];

            p[i] = max(p[i - 1], p[i]);
            dp[i][0] = p[i]; 

            if (i >= m) {
                dp[i][1] = dp[i - 1][1] + p[i] - p[i - 1]; 
                dp[i][1] = min(dp[i][1], dp[i - m][0]); 
            }
        }

        return k - dp[n - 1][1];
    }
};