class Solution {
public:
    int countbits(long long x) {
        int cnt = 0;
        while (x > 0) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long target = (long long)num1 - (long long)k * num2;

            if (target < 0) continue;

            int bits = countbits(target);

            if (bits <= k && k <= target) {
                return k;
            }
        }
        return -1;
    }
};
