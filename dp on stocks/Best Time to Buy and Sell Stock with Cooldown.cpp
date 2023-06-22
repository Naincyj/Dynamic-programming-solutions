class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        int profit=0;
         for(int i=n-1;i>=0;i--)
         {
             for(int j=0;j<2;j++)
             {
                 if(j==1)
                 {     if(i==(n-1))
                      profit=0;
                      else
                      profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                 }
                 else
                 {   profit=0;
                        
                          if(i==(n-1))
                          profit=prices[i];
                        else  if(i==(n-2))
                          profit=max(prices[i],dp[n-1][0]);

                         else 
                          {
                              profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                          }
                 }
                 dp[i][j]=profit;
             }
         }
         return dp[0][1];
    }
};