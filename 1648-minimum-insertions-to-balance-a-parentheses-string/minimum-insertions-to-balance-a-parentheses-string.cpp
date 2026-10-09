class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                
                if (open > 0) {
                    open--;
                } else {
                    ans++;
                }
            }
        }       
        return ans + open * 2;
    }
};