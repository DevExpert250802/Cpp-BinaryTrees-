# include <iostream>
using namespace std;
const int N = 1e5+10;

int dp [N]; // global variable

int fib (int n){
	if(n<=1) return n;
		if(dp[n]!=-1) return dp[n];
	return dp[n] =fib(n-1)+ fib (n-2);
}

int main(){

memset(dp,-1,sizeof (dp));
int n ;
cin >>n;
cout << fib(n);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(n<=1) return dp[n]=n; 

// As if this DP vector is used later for any purpose
// dp[0] and dp[1] will print out -1.

///////////////////////////////////////////////////////////////////////////////////////////


// error - dp not declared in scope;

#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n<=1) return n;
		if(dp[n]!= -1) return dp[n];
	return dp[n] =fib(n-1) + fib (n-2);
}

int main(){

int n ;
cin >>n;
int dp[n+1]; 
memset(dp,-1,sizeof (dp));
cout << fib(n);
return 0;
}



//////

#include <bits/stdc++.h>                 //## Approach
using namespace std;

int fib(int n, int dp[]){
	if(n<=1) return n;
		if(dp[n]!= -1) return dp[n];

	return dp[n+1] = fib(n-1,dp) + fib(n-2,dp);
}

int main(){

int n ;
cin >> n;
int dp[n+1]; 
memset(dp,-1,sizeof(dp));
cout << fib(n,dp);
return 0;
}




//###
                                                  //      USING VECTOR


#include <bits/stdc++.h>                
using namespace std;

int fib(int n, vector<int> &dp){
	if(n<=1) return n;

		if(dp[n]!= -1) return dp[n];

	return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main(){

int n ;
cin >>n;

vector<int> dp(n+1,-1);
cout << fib(n,dp);
return 0;
}

// T.C. = O(N)
// S.C. = 0(N) + O(N) (Stack space recursion + array )


 //// ###



#include <bits/stdc++.h>                
using namespace std;

int fib(int n, vector<int> &dp){
	
	dp[0]=0;
	dp[1]=1;

 for (int i=2 ; i<= n; i++){
	 dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
}

int main(){
int n ;
cin >>n;

vector<int> dp(n+1,-1);
	
cout << fib(n,dp);
return 0;
}

// T.C. = O(N)
// S.C. = 0(N) ( array )



/// ###

#include <bits/stdc++.h>                
using namespace std;

    int fib(int n) {
         if(n==0)return 0;
         int prev2 =0 , prev = 1;
            for(int i =2;i<=n;i++){
            int curr_i = prev + prev2;
            prev2 = prev;
            prev =  curr_i;
        }
        return prev;
    }

int main(){
int n ;
cin >>n;
	
cout << fib(n);
return 0;
}

// T.C. = O(N)
// S.C. = 0(1)










// LeetCode(509)


class Solution {
public:
   int fib(int n) {
         if(n<=1) return n;
           return fib(n-1)+fib(n-2);
        }

  };
    
// T.C. = O(2^N) S.C.= O(N)   overlapping subproblems -> solution memorization 
    int f(int n, vector<int>&dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
         return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n){
         vector<int>dp(n+1,-1);
         return f(n,dp);
    }
};
//T.C. = O(N) S.C.= O(N)+ O(N)  recursive stack space + dp space -> solution  tabulation
  int f(int n, vector<int>&dp) 
    {
      dp[0]=0 ; dp[1]=1;
      for(int i=2; i<=n; i++){
          dp[i]=f(i-1,dp)+f(i-2,dp);
          }
          return dp[n];
    }
    int fib(int n){
         vector<int>dp(n+1,-1);
         return f(n,dp);
    }
}; 
// T.C. = O(N) S.C. = O(N)   dp space -> solution  space optimize 
    int fib(int n){
       int  prev2=0 , prev1=1;
       if(n==0) return 0;
       else{
        for(int i=2; i<=n; i++){
         int curr_i = prev2 + prev1;
         prev2=prev1;
          prev1=curr_i;
          }
       }
         return prev1;
    }
};     
// T.C. = O(N) S.C. = O(1)   dp space -> solution  space optimize 
