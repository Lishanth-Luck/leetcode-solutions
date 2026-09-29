class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
         int m=grid.size(),n=grid[0].size();
        if((m+n-1)%2||grid[0][0]==')'||grid[m-1][n-1]=='(') return false;
        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                auto add=[&](int x){
                    for(int b:dp[x][j]){
                        int nb=b+(grid[i][j]=='('?1:-1);
                        if(nb>=0) dp[i][j].insert(nb);
                    }
                };
                if(i) add(i-1);
                if(j){
                    for(int b:dp[i][j-1]){
                        int nb=b+(grid[i][j]=='('?1:-1);
                        if(nb>=0) dp[i][j].insert(nb);
                    }
                }
            }
        }
        return dp[m-1][n-1].count(0);
    }
};