class Solution{
  public:
    int longestPalinSubseq(string A) {
        
        string B=A;
        reverse(B.begin(),B.end());
        
        int n=A.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                curr[j]=1+prev[j-1];
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return prev[n];
    }
}