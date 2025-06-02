#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll>
ll cap[1001][1001],r[1001][1001], lv[1001],pos[1001];
vector<ll>g[1001];
ll n,e,s,t;
void bfs(){
	f(i,1,n) lv[i]=0;
	lv[s]=1;
	queue<ll>q;
	q.push(s);
	while(!q.empty()){
		ll top=q.front();
		q.pop();
		for(auto x:g[top]){
			if(lv[x]==0&&r[top][x]>0){
				q.push(x);
				lv[x]=lv[top]+1;
				if(x==t) return;
			}
		}
	}
}
ll inf=1000001;
ll dfs(ll i,ll minr){
	if(i==t) return minr;
	for(;pos[i]<g[i].size();pos[i]++){
		ll j=g[i][pos[i]];
		if(lv[j]!=lv[i]+1) continue;
		if(r[i][j]<=0) continue;
		minr=min(minr,r[i][j]);
		ll x=dfs(j,minr);
		if(x!=0) {
			r[i][j]-=x;
			r[j][i]+=x;
			return x;
		}
	}
	return 0;
}
ll dinic(){
	ll ans=0;
	while(1){
		bfs();
		if(lv[t]==0) break;
		f(i,1,n) pos[i]=0;
		while(1){
			ll x=dfs(s,inf);
			if(x==0) break;
			ans+=x;
		}
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
	cout<<"Maximum flow: "<<dinic()<<endl;
	f(i,1,n){
		f(j,1,n){
			if(r[j][i]>0&&cap[i][j]>0){
				cout<<i<< " -> "<<j<<": "<<r[j][i]<<endl;
			}
		}
	}
}
