class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // Store positions for each character
        vector<deque<int>> pos(26);
        for (int i = 0; i < n; ++i)
            pos[s[i] - 'a'].push_back(i);

        vector<pair<int,int>> pairs;
        int center = -1;

        // Create (left, right) index pairs
        for (int c = 0; c < 26; ++c) {
            while (pos[c].size() >= 2) {
                int left = pos[c].front(); pos[c].pop_front();
                int right = pos[c].back(); pos[c].pop_back();
                pairs.emplace_back(left, right);
            }
            if (!pos[c].empty()) center = pos[c].front();
        }

        // Sort by left index to preserve original order
        sort(pairs.begin(), pairs.end());

        // Build target permutation
        vector<int> target;
        target.reserve(n);
        for (auto &p : pairs) target.push_back(p.first);
        if (center != -1) target.push_back(center);
        for (int i = (int)pairs.size() - 1; i >= 0; --i)
            target.push_back(pairs[i].second);

        // Fenwick Tree for inversion counting
        struct Fenwick {
            int n; vector<int> bit;
            Fenwick(int n): n(n), bit(n+1, 0) {}
            void add(int idx) { for (++idx; idx <= n; idx += idx & -idx) bit[idx]++; }
            int sum(int idx) { int res = 0; for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx]; return res; }
        };

        Fenwick fw(n);
        long long moves = 0;
        for (int i = 0; i < n; ++i) {
            int idx = target[i];
            int countLE = fw.sum(idx);
            moves += (i - countLE);
            fw.add(idx);
        }

        return (int)moves;
    }
};
