//for all posible shortest paths o(n^3)
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
//typedef pair<int,int>pii;
int n,e,w;
int d[100][100],dist[100][100];
void fw(){
	rep(i,n+1){
		rep(j,n+1)
			dist[i][j]=d[i][j];	
	}
	rep(k,n+1){
		rep(i,n+1){
			rep(j,n+1)
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
		}
	}
}
int main(){
	int x,y;
	printf("nodes edges\n");
	scanf("%d %d",&n,&e);
	rep(i,100){
		rep(j,100){
			if(i!=j) d[i][j]=999;
			else d[i][j]=0; 
		}
	}
	rep(i,e){
		scanf("%d %d %d",&x,&y,&w);
		d[x][y]=w;
		d[y][x]=w;
	}
	fw();
	int src,dest;
	printf("enter source and destination \n");
	scanf("%d %d",&src,&dest);
	printf("distance b/w %d and %d is %d \n",src,dest,dist[src][dest]);
	rep(i,n+1){
		rep(j,n+1){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
