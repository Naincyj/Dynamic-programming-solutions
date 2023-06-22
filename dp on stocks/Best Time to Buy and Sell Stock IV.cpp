class Solution {
public:
    int maxProfit(int transactions, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(transactions+1,0));
         vector<vector<int>>curr(2,vector<int>(transactions+1,0));
         for(int i=1;i<=transactions;i++)
         prev[0][i]=prices[n-1];
         int profit=0;
         for(int i=n-2;i>=0;i--)
         {
             for(int j=0;j<2;j++)
             {
                 for(int k=1;k<=transactions;k++)
                 {
                           if(j==1){
        profit=max(-prices[i]+prev[0][k],prev[1][k]);                     
                           }
                           else
                           {
profit=max(prices[i]+prev[1][k-1],prev[0][k]);                          
                           }
                           curr[j][k]=profit;
                 }
             }
             prev=curr;
         }
         return prev[1][transactions];
    }
};