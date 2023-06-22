vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
            
            
            vector<int>dp(n,1);
            vector<int>hash(n);
            for(int i=0;i<n;i++)
            hash[i]=i;
            int lastindex=0;
            int maxi=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(arr[j]<arr[i])
                    {
                        if((1+dp[j])>dp[i])
                       { dp[i]=1+dp[j];
                        hash[i]=j;}
                    }
                }
                if(dp[i]>maxi)
                {
                    maxi=dp[i];
                    lastindex=i;
                }
                
            }
            
            vector<int>ans;
             ans.push_back(arr[lastindex]);
            
            while(hash[lastindex]!=lastindex)
            {
            
                lastindex=hash[lastindex];
                 ans.push_back(arr[lastindex]);
            }
            
            
          reverse(ans.begin(),ans.end());        
            
            return ans;
            
            
            
    }