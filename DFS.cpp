#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100];
int visit[100];
void DFS(int node){
	visit[node]=1;
	cout<<node<<" ";
	for(int i=0;i<graph[node].size();++i){
		if(!visit[graph[node][i]])
			DFS(graph[node][i]);
	}
}
int main(){
	memset(visit,0,sizeof(visit));
	int x,y,nodes,edges;
	cin>>nodes;
	cin>>edges;
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=nodes;i++){
		cout<<"connections for node "<<i<<": "; 
		for(int j=0;j<graph[i].size();j++){
			if(j!=graph[i].size()-1)
				cout<<graph[i][j]<<" -->";
			else
				cout<<graph[i][j]<<endl;
		}
	}
	for(int i=1;i<=nodes;i++){
		if(!visit[i])
			DFS(i);		
	}
	cout<<endl;
	return 0;
}
