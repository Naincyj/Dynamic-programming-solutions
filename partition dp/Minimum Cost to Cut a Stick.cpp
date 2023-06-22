class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
          int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
             
             for(int i=m-2;i>0;i--)
             {
                 for(int j=i;j<m-1;j++)
                 {  
                       int mini=1e9+7;
                       for(int k=i;k<=j;k++)
                       {
        int cut=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
            mini=min(mini,cut);
                       }
                       dp[i][j]=mini;
                 
                    
                 }
             }
             return dp[1][m-2];

    }
};