class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }

private:
    const double EPS = 1e-6;

    bool dfs(vector<double> nums) {
        // Base case: only one number left
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> rest;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) rest.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                vector<double> candidates;
                candidates.push_back(a + b);
                candidates.push_back(a - b);
                candidates.push_back(b - a);
                candidates.push_back(a * b);
                if (fabs(b) > EPS) candidates.push_back(a / b);
                if (fabs(a) > EPS) candidates.push_back(b / a);

                for (double c : candidates) {
                    rest.push_back(c);
                    if (dfs(rest)) return true;
                    rest.pop_back();
                }
            }
        }
        return false;
    }
};
