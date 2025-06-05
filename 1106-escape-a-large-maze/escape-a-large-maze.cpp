class Solution {
public:
    string encode(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }

    bool bfs(vector<int>& start, vector<int>& end, unordered_set<string>& blockedSet) {
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited.insert(encode(start[0], start[1]));

        int directions[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int maxArea = 20000;

        while (!q.empty() && visited.size() < maxArea) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < 1000000 && ny < 1000000) {
                    string key = encode(nx, ny);
                    if (!blockedSet.count(key) && !visited.count(key)) {
                        if (nx == end[0] && ny == end[1]) return true;
                        visited.insert(key);
                        q.push({nx, ny});
                    }
                }
            }
        }

        return visited.size() >= maxArea;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<string> blockedSet;
        for (const auto& b : blocked) {
            blockedSet.insert(encode(b[0], b[1]));
        }

        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};
