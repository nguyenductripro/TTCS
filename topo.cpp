#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll>
vector<ll>rev_topo;
ll check[10000];
bool topo(ll i,vector<ll> a[]){
	check[i]=1;
	for(auto x:a[i]){
		if(check[x]==1){
			return false; // có chu trình
		}
		else if(check[x]==0){
			check[x]=1;
			bool tmp=topo(x,a);
			if(tmp==false) return false; // có chu trình
		}
	}
	check[i]=2;
	rev_topo.push_back(i);
	return true;
}
int main(){
	freopen("in.inp","r",stdin);
	ll n,m;
	cin>>n>>m;
	vector<ll> a[n+1];
	f(i,1,n) check [i]=0;
	f(i,1,m){
		ll c,d;
		cin>>c>>d;
		a[c].push_back(d);
	}
	f(i,1,n) {
		if(check[i]==0) {
			if(!topo(i,a)) return 0;
		}
	}
	reverse(rev_topo.begin(),rev_topo.end());
	for(auto x:rev_topo){
		cout<<x<<" ";
	}
}
