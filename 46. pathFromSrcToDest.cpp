#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
using namespace std;

void dfs(int str,int end,vector<int> &vis,vector<int> &temp,vector<int> &path,vector<vector<int>> &graph){
    temp.push_back(str);

    if(str==end){
        path=temp;
        return;
    }

    vis[str]=1;
    
    for(auto node:graph[str]){
        if(!vis[node])
            dfs(node,end,vis,temp,path,graph);
    }
    temp.pop_back();
}

int32_t main(){
    int n, q;
    cin>>n>>q;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    

    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0;i<q;i++){
        int str,end;
        cin>>str>>end;

        vector<int> temp, vis(n+1,0);
        vector<int> path;

        dfs(str,end,vis,temp,path,graph);
    }
}
