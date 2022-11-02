/*
Given a string str and another string patt. 
Find the minimum index of the character in str that is also present in patt.

Input:
str = geeksforgeeks
patt = set
Output: 1
Explanation: e is the character which is present in given str 
"geeksforgeeks" and is also presen in patt "set". 
Minimum index of e is 1. 

TC : O(N)
SC : O(26)
*/

int minIndexChar(string str, string patt)
{
    // Your code here
    unordered_map<char,int> mp;
    
    for(int i=0;i<patt.size();i++){
        mp[patt[i]]++;
    }
    
    for(int i=0;i<str.size();i++){
        if(mp[str[i]]>0)
            return i;
    }
    
    return -1;
}