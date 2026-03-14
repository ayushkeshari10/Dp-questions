#include<bits/stdc++.h>
vector<int> parent, ranks;
vector<vector<int>>cycles;
using namespace std;
int find(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=find(parent[node]);
}
void unionr(int u,int v){
    int ulp_u=find(u);
    int ulp_v=find(v);
    if(ulp_u==ulp_v){
      cycles.push_back({u,v});
      return;
    }
    else if(ranks[ulp_u]<ranks[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else if(ranks[ulp_v]<ranks[ulp_u]){
        parent[ulp_v]=ulp_u;
    }
    else {
        parent[ulp_v]=ulp_u;
        ranks[ulp_u]++;
    }
}
int main(){
    int n;
    cin>>n;
    parent.resize(n+1);
    ranks.resize(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    vector<vector<int>>roads;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        roads.push_back({u,v});
        unionr(u,v);
    }
   vector<int>compo;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            compo.push_back(i);
        }
    }
    int  
    for(int i=0;i<compo)
}