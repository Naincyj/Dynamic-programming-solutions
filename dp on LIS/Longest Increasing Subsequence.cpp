class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
    
         vector<int>dp(n+1,0);
            dp[0]=1;
            for(int i=1;i<(n+1);i++)
            if(nums[i-1]<nums[n-1])
            dp[i]=1;

            for(int i=n-2;i>=0;i--)
            {
                for(int j=0;j<(n+1);j++)
                {
                    int take=0;
                    if(j==0||(nums[i]>nums[j-1]))
                    take=1+dp[i+1];
                    int not_take=dp[j];

                    dp[j]=max(take,not_take);
                }
                
            }


        return dp[0];
    }
};