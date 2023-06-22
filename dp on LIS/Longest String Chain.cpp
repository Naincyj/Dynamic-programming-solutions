class Solution {
public:
bool isSubsequence(int n,string s1,string s2)
{     while(n--)
{
    string temp=s1;
    if(temp.erase(n,1)==s2)
    return true;
}
return false;
                
                
}


    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.length()<b.length();
        });
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[j].size()==(words[i].size()-1))
                {
                    if(isSubsequence(words[i].size(),words[i],words[j])==true)
                     {
                         dp[i]=max(dp[i],1+dp[j]);
                     }
                }
            }
            maxi=max(maxi,dp[i]);
        }
     //  for(int i=0;i<n;i++)
        //cout<<dp[i]<<" ";
        return maxi;
        
    }
};