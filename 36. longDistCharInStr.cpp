/*
Given a string S, find length of the longest substring with all distinct characters. 
Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.

TC: O(N)   SC: O(no. of dist char)
*/
int longestSubstrDistinctChars (string s)
{
    unordered_map<char,int> mp;
    int mxmDistLen=0;
    
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]==0){
            mp[s[i]]=i;
            int mpSize=mp.size();
            
            mxmDistLen=max(mxmDistLen,mpSize);
        }
        else{
            i=mp[s[i]];
            mp.clear();
        }
    }
    
    return mxmDistLen;
}