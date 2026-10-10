//Lishanth
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> d(n);
        long long s = 0;
        int mx = 0;
        long long k = (long long)k1 + k2;
        
        for (int i = 0; i < n; ++i) {
            d[i] = abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = max(mx, d[i]);
        }
        

        if (s <= k) return 0;
    
        int left = 0, right = mx;
        while (left < right) {
            int mid = (left + right) >> 1;
            long long t = 0;
            for (int v : d) {
                t += max(0, v - mid);
            }
            if (t <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            long long operations = max(0, d[i] - left);
            k -= operations;
            d[i] = min(d[i], left);
        }
        
        for (int i = 0; i < n && k > 0; ++i) {
            if (d[i] == left) {
                --k;
                --d[i];
            }
        }
        
        long long ans = 0;
        for (int v : d) {
            ans += (long long)v * v;
        }
        return ans;
    }
};
