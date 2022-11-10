/*
Given two strings a and b consisting of lowercase characters. 
The task is to check whether two given strings are an anagram of each other or not. 
An anagram of a string is another string that contains the same characters, only 
the order of characters can be different. For example, act and tac are an anagram of each other.

TC : O(|a|+|b|)
SC : O(Number of distinct characters)
*/
bool isAnagram(string a, string b){
    vector<int> mpA(26,0),mpB(26,0);
    
    for(int i=0;i<a.size();i++){
        mpA[a[i]-'a']++;
    }
    
    for(int i=0;i<b.size();i++){
        mpB[b[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(mpA[i]!=mpB[i])
            return false;
    }
    
    return true;
}
