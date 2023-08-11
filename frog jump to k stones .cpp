#include <bits/stdc++.h>

/*  There are N stones, numbered 1,2,…, N. For each i (1≤i≤N), the height of Stone i is h i.
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone I, jump to one of the following: Stone  i+1,i+2,…,i+K. Here, a cost of ∣h i−h j∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N. */

using namespace std;

int f(int ind, vector<int> &heights, int k) {
  if (ind <= 0)
    return 0;

  int minsteps = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (ind - j >= 0) {
      int jump = f(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);
      minsteps = min(minsteps, jump);
    }
  }
  return minsteps;
}

int frogJump(int n, vector<int> &heights, int k) {

  return f(n - 1, heights, k);
}





#include <bits/stdc++.h>

using namespace std;

int f(int ind, vector<int> &heights, int k,vector<int>& dp) {
  if (ind == 0)
    return 0;

    if(dp[ind]!=-1) return dp[ind];

  int minsteps = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (ind - j >= 0) {
      int jump = f(ind - j, heights, k,dp) + abs(heights[ind] - heights[ind - j]);
     minsteps = min(minsteps, jump);
    }
  }
  return dp[ind]= mmSteps;
}

int frogJump(int n, vector<int> &heights, int k) {

   vector<int>dp(n,-1);
  return f(n - 1, heights, k,dp);
}





#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int frogJump(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return f(n, height, dp, k);
}
