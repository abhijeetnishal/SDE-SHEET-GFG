/*
Given an array A of positive integers. Your task is to find the leaders in the array. 
An element of array is leader if it is greater than or equal to all the elements to its right side. 
The rightmost element is always a leader. 

Input:
n = 6
A[] = {16,17,4,3,5,2}

Output: 17 5 2

*/

//TC : O(N*N) ASC : O(1)
vector<int> leaders(int a[], int n){
    vector<int> ans; 
    
    for(int i=0;i<n-1;i++){
        int curval=a[i];
        bool check=true;
        
        for(int j=i+1;j<n;j++){
            if(curval<a[j])
                check=false;
        }
        if(check)
            ans.push_back(curval);
    }
    ans.push_back(a[n-1]);
    return ans;
}


//TC : O(N) ASC : O(N) (stack)
vector<int> leaders(int a[], int n){
    vector<int> ans; 
    stack<int> st;
    
    st.push(a[n-1]);
    ans.push_back(a[n-1]);

    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=a[i]){
                st.pop();
            }

        if(st.empty())
            ans.push_back(a[i]);

        st.push(a[i]);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}


//TC : O(N) ASC : O(1)
vector<int> leaders(int a[], int n){
    vector<int> ans; 
    
    int mxm=-1;
    
    for(int i=n-1;i>=0;i--){
        if(mxm<=a[i]){
            ans.push_back(a[i]);
            mxm=a[i];
        }
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
