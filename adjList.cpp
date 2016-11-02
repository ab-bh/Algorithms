#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10]; 
int main(){
	ios::sync_with_stdio(false);
	printf("Adjacency List for Graph(better when scarse adj matrix\n");
	int x,y,nodes,edges;
	cin>>nodes;	
	cin>>edges;
	for(int i=0;i<edges;++i){
		cin>>x>>y;
		graph[x].push_back(y);
	}
	for(int i=1;i<=nodes;++i){
		cout<<"adjacency list for node "<<i<<" is->";
		for(int j=0;j<graph[i].size();++j){
			if(j==graph[i].size()-1)
				cout<<graph[i][j]<<endl;
			else
				cout<<graph[i][j]<<"->";
		}
	}
	return 0;
}
