#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define maxs 100001
#define ll long long
vector<ll>arr[maxs];
queue< pair<ll,ll> > q;
ll visit[maxs],dist[maxs];
void bfs(ll v){
	q.push(mp(v,0));
	while(!q.empty()){
		ll a=q.front().first;
		ll b=q.front().second;
		visit[a]=1;
		for(ll i=0;i<arr[a].size();++i){
			if(!visit[ arr[a][i] ])
				q.push(mp(arr[a][i],b+1));
		}
		dist[a]=b;
		q.pop();
	}
}
int main(){
	ll n,c,d;
	scanf("%lld",&n);
	for(ll i=0;i<n-1;++i){
		scanf("%lld %lld",&c,&d);
		arr[c].pb(d);
		arr[d].pb(c);
	}
	memset(visit,0,sizeof(visit));
	memset(dist,0,sizeof(dist));
	bfs(1);
	ll temp=0;
	for(ll i=1;i<=n;++i){
		if(dist[i]>dist[temp])
			temp=i;
	}
	memset(visit,0,sizeof(visit));
	memset(dist,0,sizeof(dist));
	bfs(temp);
	temp=0;
	for(ll i=1;i<=n;++i)
		temp=max(temp,dist[i]);
	printf("%lld",temp);
	return 0;
}
