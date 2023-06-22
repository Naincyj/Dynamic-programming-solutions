#include <bits/stdc++.h> 
int minInsertion(string &str)
{
    string stg=str;
    reverse(stg.begin(),stg.end());
    int n=str.size();

    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==stg[j-1])
            curr[j]=1+prev[j-1];
            else
            curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }

    return (n-prev[n]);


}