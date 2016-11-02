#include<bits/stdc++.h>
using namespace std;
#define maxs 1001
#define mp make_pair
typedef pair< int, pair<int,int> >pii;

priority_queue< pii,vector<pii>,greater<pii> > pq;
int root_arr[maxs],size_arr[maxs];

int root(int node ){										//function to match root node for cycle detection
	while(root_arr[ node ]!= node)
		node =root_arr[ root_arr[ node ] ];
	return node;
}

void unions(int a,int b){									//union step using size heuristics
	int root_a=root(a);
	int root_b=root(b);
	if(size_arr[ root_a ]>size_arr[ root_b ]){
		root_arr[ root_b ]=root_arr[ root_a ];
		size_arr[ root_a ] += size_arr[ root_b ];
	}
	else{
		root_arr[ root_a ] = root_arr[ root_b ];
		size_arr[ root_b ] += size_arr[ root_a ];
	}
}

int main(){
	int w,a,b,e,n;
	cout<<"enter number of nodes"<<endl;
	cin>>n;
	cout<<"enter number of edges"<<endl;
	cin>>e;
	for(int i=1;i<=n;++i){
		root_arr[i]=i;
		size_arr[i]=1;
	}
		
	for(int i=1;i<=e;++i){
		cout<<"enter node1 node2 weight"<<endl;				//generating connections
		cin>>a>>b>>w;
		pq.push(mp(w,mp(a,b)));
	}
	int min_dist=0;
	while(!pq.empty()){										//the kruskal step
		pii temp=pq.top();
		pq.pop();
		if(root(temp.second.first)!=root(temp.second.second)){
			min_dist+=temp.first;
			unions(temp.second.first,temp.second.second);	
		}
	}
	cout<<"min_dist is ---> "<<min_dist<<endl;				//displying minimum distance
	return 0;
}