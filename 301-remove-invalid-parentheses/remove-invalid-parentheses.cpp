class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        function<void(int, int, int, string)> dfs =
            [&](int index, int lRemove, int rRemove, string current) {
                if (index == s.size()) {
                    if (lRemove == 0 && rRemove == 0) {
                        int balance = 0;

                        for (char c : current) {
                            if (c == '(')
                                balance++;
                            else if (c == ')') {
                                balance--;
                                if (balance < 0)
                                    return;
                            }
                        }

                        if (balance == 0)
                            ans.push_back(current);
                    }
                    return;
                }

                char c = s[index];

                if (c == '(' && lRemove > 0)
                    dfs(index + 1, lRemove - 1, rRemove, current);

                if (c == ')' && rRemove > 0)
                    dfs(index + 1, lRemove, rRemove - 1, current);

                dfs(index + 1, lRemove, rRemove, current + c);
            };

        dfs(0, left, right, "");

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};