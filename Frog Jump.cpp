/* Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j,
 the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference.
 We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.*/

#include<bits/stdc++.h>
int f(int ind, vector<int> &heights) {
  if (ind <=0)
    return 0;
  int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if (ind > 1)
    right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
  return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
   return f(n-1,heights);
}







#include<bits/stdc++.h>
int f(int ind, vector<int> &heights,vector<int>&dp) {
  if (ind <=0)
    return 0;
    if(dp[ind]!=-1) return dp[ind];
  int left = f(ind- 1, heights,dp) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if (ind > 1)
    right = f(ind - 2, heights,dp) + abs(heights[ind] - heights[ind - 2]);
 return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
  vector<int>dp(n,-1);
   return f(n-1,heights,dp);
}





#include<bits/stdc++.h>
int f(int n, vector<int> &heights,vector<int>&dp) {
  dp[0]=0;
  for (int i = 1; i <= n; i++) {
    int left = dp[i-1] + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i> 1)
      right = dp[i-2] + abs(heights[i] - heights[i - 2]);
    dp[i] = min(left, right);
  }
  return dp[n];
}
int frogJump(int n, vector<int> &heights)
{
  vector<int>dp(n,-1);
   return f(n-1,heights,dp);
}






#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
  vector<int>dp(n,-1);
    dp[0]=0;
  for (int i = 1; i < n; i++) {
    int left = dp[i-1] + abs(heights[i]-heights[i-1]);
    int right = INT_MAX;
    if (i> 1)
      right = dp[i-2] + abs(heights[i]-heights[i-2]);
    dp[i] = min(left, right);
  }
  return dp[n-1];
}





#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    int prev=0, prev2=0;
  for (int i = 1; i < n; i++) {
    int left = prev + abs(heights[i]-heights[i-1]);
    int right = INT_MAX;
    if (i> 1)
      right = prev2 + abs(heights[i]-heights[i-2]);
   int curr= min(left, right);
   prev2=prev;
   prev =curr;
  }
  return prev;
}
