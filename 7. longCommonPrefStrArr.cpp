/*

Given a array of N strings, find the longest common prefix among all strings present in the array.
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.

TC : O(N*max(|arr[i]|))
SC : O(max(|arr[i]|))

*/


string longestCommonPrefix (string arr[], int N){
    string ans= arr[0];

    for(int i=0; i<N;i++){
        int k=0;

        while(k<arr[i].length() && k<ans.length()){
            if(arr[i][k]!=ans[k]) break;
            k++;
        }

        ans =ans.substr(0, k);

        if(ans.length()==0) 
            return "-1";
    }
    return ans;
}


//another approach with same time and space
string longestCommonPrefix(vector<string>& strs) {
         string ans="";
         int strOneSize=strs[0].size();

         for(int i=0;i<strOneSize;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i])
                    return ans;
            }
            ans+=strs[0][i];
         }

         return ans;
}
