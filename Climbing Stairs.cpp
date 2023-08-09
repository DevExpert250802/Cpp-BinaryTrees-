/ * Q2)   Problem Statement: Given the number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair.
 At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.*/



class Solution {
public:
  int climbStairs(int n) {
if (n==0) return 1;
if (n==1) return 1;
return climbStairs(n-1)+ climbStairs(n-2);
 }
};


// T.C. = O(2^N) S.C.= O(N)   overlapping subproblems -> solution memorization



class Solution {
public:
  int f(int n,vector<int>&dp ){
	if (n==1) return 1;
  if (n==2) return 2;
	 if(dp[n]!=-1)  return dp[n];
return dp[n]= f(n-1,dp)+ f(n-2,dp);
}
int climbStairs(int n){
	vector<int>dp(n+1,-1);
return f(n,dp);
 }
}; 



// T.C. = O(N) S.C.= O(N)+ O(N)  recursive stack space + dp space -> solution  tabulation



class Solution {
public:
  int climbStairs(int n) {
         vector<int>dp(n+1,-1);
        if(n==1) return 1;
        dp[1]=1; dp[2]=2;
        for(int i= 3; i<=n; i++ ) {
            dp[i]= dp[i-1] + dp[i-2];
        }
        return dp[n];

    }
};  



// T.C. = O(N) S.C.= O(N)  recursive stack space   -> solution  tabulation

 

class Solution {
public:
	int climbStairs(int n) {
	//	if(n==0)return 1;
	//	if(n==1)return 1;
		int prev=1, prev2=1;
		for(int i=2; i<=n; i++){
			int curr = prev + prev2;
			prev2 =prev; prev=curr;
		}
		return prev;
	}

}; 


/* T.C. = O(N) S.C.= O(N)  recursive stack space  */
