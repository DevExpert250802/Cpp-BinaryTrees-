/* A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day.
There are merit points associated with performing an activity each day. 
The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.
We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn. */

 #include <bits/stdc++.h>

long long int f(int ind, vector<int> &nums, vector<long long int> &dp) {
    dp[0] = nums[0];

    for (int i = 1; i <= ind; i++) {
        long long int pick = nums[i];
        if (i > 1) {
            pick += dp[i - 2];
        }
        long long int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[ind - 1];
}

long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    vector<long long int> dp(n, -1);
    if (n == 1)
        return valueInHouse[0];

    vector<int> excludeFirst;
    vector<int> includeFirst;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            excludeFirst.push_back(valueInHouse[i]);
        if (i != n - 1)
            includeFirst.push_back(valueInHouse[i]);
    }
    return max(f(n - 1, excludeFirst, dp), f(n - 1, includeFirst, dp));
}



















#include <bits/stdc++.h>
 long long int f(vector<int> &arr){
     int n = arr.size();
   long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
      long long  int pick = arr[i];
        if(i>1)
            pick += prev2;
       long long int nonPick = 0 + prev;
        
       long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

 long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    vector<int> excludeFirst;
    vector<int> includeFirst;
     if(n==1)return valueInHouse[0];
    
    for(int i=0; i<n; i++){
        
         if(i!=0) excludeFirst.push_back(valueInHouse[i]);
        if(i!=n-1) includeFirst.push_back(valueInHouse[i]);
    }
    return max(f(excludeFirst),f(includeFirst));
}


















#include <bits/stdc++.h>

long long int f(vector<int> &arr, int n) {
    long long int prev = arr[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++) {
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        long long int nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}
long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];

    vector<int> excludeFirst;
    vector<int> includeFirst;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            excludeFirst.push_back(valueInHouse[i]);
        if (i != n - 1)
            includeFirst.push_back(valueInHouse[i]);
    }
    return max(f(excludeFirst, n - 1), f(includeFirst, n - 1));
}
