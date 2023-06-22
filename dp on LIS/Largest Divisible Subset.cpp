class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
                vector<int>dp(n,1);
                vector<int>hash(n,0);
            int maxi=1;
            int lastindex=0;
                for(int i=1;i<n;i++)
                {    hash[i]=i;
                    for(int j=0;j<i;j++){
                        if(nums[i]%nums[j]==0)
                        {
                            if(1+dp[j]>dp[i])
                            {
                                dp[i]=1+dp[j];
                                hash[i]=j;
                            }
                        }
                    }
                    if(maxi<dp[i])
                    {
                        maxi=dp[i];
                        lastindex=i;
                    }

                }

             vector<int>ans;
             ans.push_back(nums[lastindex]);

             while(hash[lastindex]!=lastindex)
           {
               lastindex=hash[lastindex];
               ans.push_back(nums[lastindex]);
           }
 return ans;



    }
};