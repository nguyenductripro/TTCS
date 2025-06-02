#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll
ll cap[1001][1001],parent[1001],r[1001][1001], check[1001];
vector<ll>g[1001];
ll n,e,s,t;
ll bfs(){
	queue<ll> q;
	q.push(s);
	f(i,1,n) {
		parent[i]=i;
		check[i]=0;
	}
	check[s]=1;
	while(!q.empty()){
		ll i=q.front();
		if(i==t) return 1;
		q.pop();
		//cout<<i<<endl;
		for(auto x:g[i]){
			if(check[x]==1) continue;
			if(r[i][x]==0) continue;
			q.push(x);
			parent[x]=i;
			check[x]=1;
		}
	}
	return 0;
}
ll edmondsKarp(){
	ll ans=0;
	while(1){
		if(!bfs()) break;
		ll minr=10000000;
		ll x=t;
		while(1){
			//cout<<x<<" ";
			if(x==s) break;
			ll p=parent[x];
			minr =min(minr,r[p][x]);
			x=p;
		}
		//cout<<endl;
		x=t;
		while(1){
			if(x==s) break;
			ll p=parent[x];
			r[p][x]-=minr;
			r[x][p]+=minr;
			x=p;
		}
		ans+=minr;
	}
	return ans;
}
int main(){
	freopen("in.inp","r",stdin);
	//freopen("out.oup","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>e>>s>>t;
	f(i,1,e){
		ll a,b;
		cin>>a>>b;
		cin>>cap[a][b];
		cap[b][a]=0;
		cap[a][a]=0;
		cap[b][b]=0;
		r[a][b]=cap[a][b];
		r[b][a]=0;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout<<"Maximum flow: "<<edmondsKarp()<<endl;
	f(i,1,n){
		f(j,1,n){
			if(r[j][i]>0&&cap[i][j]>0){
				cout<<i<< " -> "<<j<<": "<<r[j][i]<<endl;
			}
		}
	}
}
