class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(3,0));
         vector<vector<int>>curr(2,vector<int>(3,0));
        int profit=0;
            prev[0][1]=prices[n-1];
            prev[0][2]=prices[n-1];
            for(int i=n-2;i>=0;i--)
            {
                for(int j=0;j<2;j++)
                {
                    for(int k=1;k<3;k++)
                    {
                        if(j==1)
                        {
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
            return prev[1][2];
    }
};