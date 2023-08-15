/* Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).

At any cell we are allowed to move in only two directions:- bottom and right.*/


int f(int i,int j){
	if (i==0 && j==0) return 1;

	if(i<0 || j<0)return 0;

	int up= f(i-1,j);
	int left=f(i,j-1);

	return up+left;
}
int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}




#include <bits/stdc++.h> 

int f(int i,int j,vector<vector<int>> &dp){
	if (i ==0 && j ==0) return 1;
	if(i<0 || j<0)return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int up= f(i-1,j,dp);
	int left=f(i,j-1,dp);
	dp[i][j]= up+left;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1,n-1,dp);
}





#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else {
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}







#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {

vector<int>prev(n,0);
for(int i=0;i<m;i++){
    vector<int>curr(n,0);
	for(int j=0;j<n;j++){
		if (i==0&&j==0)curr[j]=1;
                  else {
                    int up = 0;
                    int left = 0;

                    if (i > 0)
                      up = prev[j];
                    if (j > 0)
                      left = curr[j - 1];
                    curr[j] = up + left;
                  }
        }
		prev=curr;
}
return prev[n-1];
}





// optimal way:




#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
  int N=n+m-2;
  int r= m-1;
  int result =1;

  for (int i = 1; i <= r; i++) {
    result = result * (N - r + i) / i;
  }
    return result;
}

