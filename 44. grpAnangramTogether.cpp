/*
You have been given an array/list of strings 'STR_LIST'. You are supposed to return the strings as
groups of anagrams such that strings belonging to a particular group are anagrams of one
another.

Sample Input 1:
2
4
abab baba aabb abbc
5
aecd bcda acbd abdc acda

Sample Output 1 :
aabb abab baba
abbc
abdc acbd bcda
acda
aecd

TC: O(N*(strList[i]*Log(strList[i])))  SC: O(N*max(strList[i])) 
*/
vector<vector<string>> groupAnagramsTogether(vector<string> &strList)
{
    // Write your code here. 
    unordered_map<string,vector<string>> mp;
    
    for(string s:strList){
        string temp=s;
        sort(temp.begin(),temp.end());
        
        mp[temp].push_back(s);
    }
    
    vector<vector<string>> ans;
    
    for(auto itr:mp){
        vector<string> temp;
        for(auto val:itr.second){
            temp.push_back(val);
        }
        ans.push_back(temp);
    }
    
    return ans;
}