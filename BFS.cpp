#include<bits/stdc++.h>
using namespace std;
queue<int>store;
vector<int>graph[100];
int visit[100];
void BFS(int node){
	visit[node]=1;
	store.push(node);
	while(!store.empty()){
		int v=store.front();
		store.pop();
		cout<<v<<" ";
		for(int i=0;i<graph[v].size();i++){
			if(!visit[graph[v][i]]){
				store.push(graph[v][i]);
				visit[graph[v][i]]=1;
			}
		}
	}
}
int main(){
	memset(visit,0,sizeof(visit));
	int x,y,nodes,edges;
	scanf("%d %d",&nodes,&edges);
	for(int i=0;i<edges;i++){
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=nodes;i++){
		cout<<"connections for node "<<i<<": "; 
		for(int j=0;j<graph[i].size();j++){
			if(j!=graph[i].size()-1)
				printf("%d-->",graph[i][j]);
			else
				printf("%d\n",graph[i][j]);
		}
	}
	for(int i=1;i<=nodes;i++){
		if(!visit[i])
			BFS(i);		
	}
	printf("\n");
	return 0;
}
