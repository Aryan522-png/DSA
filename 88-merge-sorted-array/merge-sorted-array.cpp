class Solution {
    void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n, vector<int>& num) {
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                num[k++] = nums1[i++];
            } else {
                num[k++] = nums2[j++];
            }
        }

        while (i < m) {
            num[k++] = nums1[i++];
        }

        while (j < n) {
            num[k++] = nums2[j++];
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num(m + n); 
        mergeArrays(nums1, m, nums2, n, num);

        for (int i = 0; i < m + n; ++i) {
            nums1[i] = num[i];
        }
    }
};
