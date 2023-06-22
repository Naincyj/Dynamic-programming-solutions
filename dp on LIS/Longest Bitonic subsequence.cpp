int LongestBitonicSequence(vector<int>nums1)
	  
	{ 
	    int n=nums1.size();
	    
	    vector<int>nums2;
	nums2=nums1;
	reverse(nums2.begin(),nums2.end());
	
	vector<int>dp1(n,1);
	vector<int>dp2(n,1);
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<i;j++)
	    {
	        if(nums1[i]>nums1[j])
	        {
	            dp1[i]=max(dp1[i],1+dp1[j]);
	        }
	        if(nums2[i]>nums2[j])
	        {
	            dp2[i]=max(dp2[i],1+dp2[j]);
	        }
	        
	    }
	}
	
	int maxi=1;
	for(int i=0;i<n;i++)
	{
	    maxi=max(maxi,dp1[i]+dp2[n-i-1]-1);
	}
	return maxi;
	        
	        
	}