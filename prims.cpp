#include <bits/stdc++.h>
using namespace std;
#define maxs 1001
#define mp make_pair
#define pb push_back
typedef  pair<int,int> pii;

priority_queue < pii, vector<pii>, greater<pii> > pq;
vector < pii > graph[maxs];
int visited[maxs];

int prims(int node){
	int min_dist=0,dist;
	pq.push(mp(0,node));
	while(!pq.empty()){
		pii a =pq.top();
		dist=a.first;
		pq.pop();
		if (visited[ a.second ]) continue;
		visited[ a.second ] =1;
		min_dist += dist;
		for(int i = 0;i<graph[ a.second ].size();++i){
			if(!visited[ graph[ a.second ][i].second ] )
				pq.push( graph[ a.second ][i] );
		} 
	}
	return min_dist;
}

 int main(){
 	memset(visited,0,sizeof(visited));
 	int w,a,b,e,n;
	cout<<"enter number of nodes"<<endl;
	cin>>n;
	cout<<"enter number of edges"<<endl;
	cin>>e;	
	for(int i=1;i<=e;++i){
		cout<<"enter node1 node2 weight"<<endl;				
		cin>>a>>b>>w;
		graph[a].pb(mp(w,b));
		graph[b].pb(mp(w,a));	
	}
	int min_dist = prims(1);
	cout<<"min_dist is ---> "<<min_dist<<endl;	
	return 0;
 }