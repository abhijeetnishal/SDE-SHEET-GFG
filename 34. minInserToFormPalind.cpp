/*
Given a string, find the minimum number of characters to be inserted to 
convert it to palindrome.

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked
with bold characters in dcbabcd

TC : O(N*N)  SC : O(N*N)

Approach:
The problem of finding minimum insertions can also be solved using Longest 
Common Subsequence (LCS) Problem. If we find out the LCS of string and its 
reverse, we know how many maximum characters can form a palindrome. We need 
to insert the remaining characters.
*/

//Memoization
int LCS(int i,int j,string s,string t,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==t[j])
        return dp[i][j]=1+LCS(i-1,j-1,s,t,dp);
    else
        return dp[i][j]=max(LCS(i-1,j,s,t,dp),LCS(i,j-1,s,t,dp));
}

int countMin(string s){
    int n=s.size();
    
    string t=s;
    reverse(t.begin(),t.end());
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int ans=n-LCS(n-1,n-1,s,t,dp);
    
    return ans;
}
