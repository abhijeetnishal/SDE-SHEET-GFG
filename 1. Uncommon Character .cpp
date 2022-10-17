/*
Given two strings A and B. Find the characters that are not common in the two strings.

Input:
A = characters
B = alphabets

Output: bclpr

Explanation: The characters 'b','c','l','p','r' 
are either present in A or B, but not in both.

TC : O(N+M)
ASC : O(1)
*/

string UncommonChars(string a, string b)
{
    int mp1[26] = {0}, mp2[26] = {0};
    int n = a.size(), m = b.size();
 
    for(auto &x: a){
      mp1[x-'a'] = 1;
    }
 
    for(auto &x: b){
      mp2[x-'a'] = 1;
    }
 
    string ans = "";
 
    for(int i = 0; i < 26; ++i){
      if(mp1[i]^mp2[i])
        ans+=char(i+'a');
    }
    if(ans == "")
      return "-1";
    else
      return ans;
}