class Solution {
public:
    bool isMatch(string s2, string s1) {
        int n=s1.size();
        int m=s2.size();
          vector<int>prev(m+1,0);
          vector<int>curr(m+1,0);
          prev[0]=1;
          int k;
          
          for(int i=1;i<=n;i++)
          {    for( k=i-1;k>=0;k--)
           if(s1[k]!='*')
           { curr[0]=false;
            break;}
             if(k<0)
            curr[0]=true;
              for(int j=1;j<=m;j++)
              {
                  if((s1[i-1]==s2[j-1])||(s1[i-1]=='?'))
                     curr[j]=prev[j-1];
                     else
                     {
                         if(s1[i-1]=='*')
                         curr[j]=prev[j]||curr[j-1];
                         else
                         curr[j]=false;
                     }

              }
              prev=curr;
          }
          return prev[m];
    }
};