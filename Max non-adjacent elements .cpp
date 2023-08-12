/* Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array*/




#include <bits/stdc++.h> 

int f(int ind,vector<int> &nums){
    if (ind==0) return nums[ind];
    if (ind<0) return 0;

int pick=nums[ind]+f(ind-2,nums);
int notpick=0+f(ind-1,nums);
return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size();
   return f(n-1,nums);
}







#include <bits/stdc++.h> 
int f(int ind,vector<int> &nums,vector<int> &dp){
    if (ind==0) return nums[ind];
    if (ind<0) return 0;
if(dp[ind]!=-1) return (dp[ind]);
int pick=nums[ind]+f(ind-2,nums,dp);
int notpick=0+f(ind-1,nums,dp);
return dp[ind]= max(pick,notpick);

}
int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size();
    vector<int>dp(n,-1);
   return f(n-1,nums,dp);
}






#include <bits/stdc++.h> 

int f(int ind,vector<int> &nums,vector<int> &dp){

    dp[0]=nums[0];

    for (int i = 1; i <=ind; i++) {
      int pick = nums[i];
      if (i > 1) {
        pick += dp[i - 2];
      }
    int  notpick = 0 + dp[i-1];
      dp[i] = max(pick, notpick);
    }
     return dp[ind];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size(); 
    vector<int>dp(n,-1);
   return f(n-1,nums,dp);
}








#include <bits/stdc++.h> 
   int f (int n,vector<int> &arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<=n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n= nums.size(); 
   return f(n-1,nums);
}


