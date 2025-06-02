#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll>

struct DSU{
	ll n;
	ll parent[100001],sz[100001];
	DSU(ll nn){
		this->n=nn;
		f(i,1,n) {
			parent[i]=i;
			sz[i]=1;
		}
	}
	ll find(ll u){
		if(u!=parent[u]) return parent[u]=find(parent[u]);
		else return u;
	}
	bool Union(ll u,ll v){
		u=find(u);
		v=find(v);
		if(u==v) return false;
		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v];
		parent[v]=u;
		sz[v]=0;
		return true;
	}
};

int main(){
	//freopen("in.inp","r",stdin);
	ll n,m;
	cin>>n>>m;
	DSU dsu(n);
	ll cnt=n;
	f(i,1,m){
		ll a,b;
		cin>>a>>b;
		if(dsu.Union(a,b)) cnt--;
	}
	cout<<cnt;
	
}
