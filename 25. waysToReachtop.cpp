/*
A frog jumps either 1, 2, or 3 steps to go to the top. 
In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
*/

//Recursion - TC : O(3^N) SC : O(N)
int cntWays(int n,int mod){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
        
    return (cntWays(n-1,mod)%mod+cntWays(n-2,mod)%mod+cntWays(n-3,mod)%mod)%mod;
}

long long countWays(int n)
{
    // your code here
    int mod=1e9+7;
    
    int ans=cntWays(n,mod);
    
    return ans;
}


//Memoization -  TC : O(N) SC : O(N)
long long cntWays(int n,int mod,vector<long long> &dp){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
        
    if(dp[n]!=-1)
        return dp[n]%mod;
        
    return dp[n]=(cntWays(n-1,mod,dp)%mod+cntWays(n-2,mod,dp)%mod
                  +cntWays(n-3,mod,dp)%mod)%mod;
}

long long countWays(int n)
{
    // your code here
    int mod=1e9+7;
    vector<long long> dp(n+1,-1);
    
    long long ans=cntWays(n,mod,dp);
    
    return ans;
}


//Iterative -  TC : O(N) SC : O(N)
long long countWays(int n){
    // your code here
    long long count[n+1];
    int mod=1e9+7;

     count[0]=1;
     if(n>=1)
        count[1]=1;
     if(n>=2)
        count[2]=2;

    // Fill the count array in bottom up manner
    for (int i=3; i<=n; i++)
        count[i]=(count[i-1]%mod+count[i-2]%mod+count[i-3]%mod)%mod;

    return count[n]%mod;
}
