class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
         vector<int>prev(2,0);
         vector<int>curr(2,0);
         prev[0]=prices[n-1]-fee;
      int profit=0;
         for(int i=n-2;i>=0;i--)
         {
             for(int j=0;j<2;j++)
             {
                 if(j==1)
                 {
     profit=max(-prices[i]+prev[0],prev[1]);           
                 }
                 else
                 {
    profit=max(prices[i]+prev[1]-fee,prev[0]);
                 }
                 curr[j]=profit;
             }
             prev=curr;
         }
         return prev[1];
    }
};