class Solution {
    public:
      int minCoins(vector<int> &coins, int sum) {
     
      vector<int> dp(sum+1, INT_MAX);
      
      
      dp[0] = 0; 
      
      
      for (int i=coins.size()-1; i>=0; i--) {
          
          
          for (int j=1; j<=sum; j++) {
              
              
              int take = INT_MAX, noTake = INT_MAX;
              
             
              if (j-coins[i]>=0 && coins[i]>0) {
                  
                  
                  take = dp[j-coins[i]]; 
                  
               
                  if (take != INT_MAX) take++; 
              }
              
  
              
              if (i+1<coins.size())
                  noTake = dp[j]; 
              
  
              dp[j] = min(take, noTake);
          }
      }
      
      if (dp[sum]!=INT_MAX) return dp[sum];
      return -1;
  }
  };