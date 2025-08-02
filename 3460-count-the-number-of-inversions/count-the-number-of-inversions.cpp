class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9+7;
        vector<int> req(n, -1);
        int maxInv = 0;
        for (auto& r : requirements) {
            req[r[0]] = r[1];
            maxInv = max(maxInv, r[1]);
        }
        if (req[0] > 0) return 0;
        req[0] = 0;

        vector<vector<int>> f(n, vector<int>(maxInv+1, 0));
        f[0][0] = 1;

        for (int i = 1; i < n; ++i) {
            int lo = 0, hi = maxInv;
            if (req[i] >= 0) lo = hi = req[i];
            for (int j = lo; j <= hi; ++j) {
                long long ways = 0;
                for (int k = 0; k <= min(i, j); ++k) {
                    ways += f[i-1][j-k];
                }
                f[i][j] = ways % MOD;
            }
        }

        return f[n-1][req[n-1] < 0 ? 0 : req[n-1]];
    }
};
