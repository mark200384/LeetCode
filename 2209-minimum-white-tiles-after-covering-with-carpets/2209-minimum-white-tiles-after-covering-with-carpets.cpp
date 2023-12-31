class Solution {
public:
    int dp[1001][1001];
    //Let DP[i][j] denote the minimum number of white tiles still visible from indices i to floor.length-1 after covering with at most j carpets.
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        floor = "#" + floor;
        //vector<vector<int>> dp(n+1, vector<int>(numCarpets+1, 1e9));
        dp[0][0]=0;
        for(int i=1; i<=n; i++) { // # of tiles
            for(int j=0; j<=numCarpets; j++) { // # of carpets
                dp[i][j] = INT_MAX/2; //initialization
                dp[i][j] = dp[i-1][j] + (floor[i]=='1'); //第i個不鋪地毯, (如果floor[i]是白色則# of min white要+1)
                if (j>=1) //有地毯
                    dp[i][j] = min(dp[i][j], i>=carpetLen ? dp[i-carpetLen][j-1]:0); //鋪地毯, 且確保i-carpetLen >=0
            }
        }
        return dp[n][numCarpets];
    }
};