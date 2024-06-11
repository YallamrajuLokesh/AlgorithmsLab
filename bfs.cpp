#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;



void bfs(int node,vector<int>adj[]){
  cout<<"enter start"<<endl;
  int start;
  cin>>start;
  map<int,bool>visited;
  queue<int> q;
  
  vector<int>ans;
  visited[node]=true;
  q.push(node);
  while(!q.empty()){
    int current=q.front();
    q.pop();
    for(auto it:adj[current]){
      if(!visited[it]){
        visited[it]=true;
        q.push(it);
      }
    }
  }
  for(auto i:ans){
    cout<<i<<" ";
  }
  cout<<endl;
}


int main(){
int V,e;
  cout<<"enter v"<<endl;
  cin>>V;
  cout<<"Enter e"<<endl;
  cin>>e;
  int u,v;
  vector<int>adj[V];

  for(int i=0;i<e;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    
  }
  bfs(V,adj);
}
