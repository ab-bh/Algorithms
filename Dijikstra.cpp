//no -ve weights included...dijikstra for =ve weight only o(nlog(n)+mlog(n)) for n no.of nodes
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>graph[100];
vector<int>dist(100,999999999);
priority_queue< pii, vector<pii>, greater<pii> >q;
int n,e,w;
int dijkstra(int s,int d){
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pii p=q.top();
		int x=p.first,y=p.second;
		q.pop();
		if(x<=dist[y]){
			for(int i=0;i<graph[y].size();++i){
				int b=graph[y][i].first;
				int c=graph[y][i].second;
				if(dist[c]>dist[y]+b){
					dist[c]=dist[y]+b;					
					q.push(make_pair(dist[c],c));
				}	
			}
		}
	}
	cout<<"vertex"<<"\t"<<"dist_from_src"<<endl;
	for(int i=1;i<=n;++i)
		cout<<i<<"\t"<<dist[i]<<endl;
	return dist[d];
}
int main(){
	int x,y;
	cout<<"nodes edges"<<endl;
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++){
		cout<<"enter node1 node2 weight"<<endl;
		scanf("%d %d %d",&x,&y,&w);
		graph[x].push_back(make_pair(w,y));
		//graph[y].push_back(make_pair(w,x));
	}
	int src,dest;
	printf("enter source node ");
	scanf("%d",&src);
	printf("\n");
	printf("enter destination node ");
	scanf("%d",&dest);
	//dijkstra(1,3);
	int min_dist=dijkstra(src,dest);
	cout<<"min_dist from src-->dest "<<min_dist<<endl;
	return 0;
}
