#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll>
//scc
ll num[10001],low[10001],check[10001],instack[10001];
ll cnt=0,ans=0;
stack<ll>s;

void dfs(ll i,vector<ll>a[]){
	cnt++;
	num[i]=cnt;
	low[i]=cnt;
	check[i]=1;
	if(instack[i]==0) {
		s.push(i);
		instack[i]=1;
	}
	for(auto x:a[i]){
		if(check[x]==0){
			dfs(x,a);
			low[i]=min(low[x],low[i]);
		}
		else if(instack[x]==1) low[i]=min(low[i],low[x]);
	}
	if(low[i]==num[i]) {
		ans++;
		while(1){
			if(s.empty()) break;
			if(s.top()==i){
				instack[s.top()]=0;
				s.pop();
				break;
			}
			if(s.empty()) break;
			instack[s.top()]=0;
			s.pop();
		}
		
	}
}
int main(){
	freopen("in.inp","r",stdin);
	//freopen("out.oup","w",stdout);
	ll n,e;
	cin>>n>>e;
	vector<ll>a[n+1];
	f(i,1,e){
		ll c,d;
		cin>>c>>d;
		a[c].push_back(d);
	}
	f(i,1,n){
		check[i]=0;
		instack[i]=0;
	}
	f(i,1,n){
		if(check[i]==0) dfs(i,a);
	}
	cout<<ans;
}

//bridge/articulation points
/*
ll n,e,timer=0,bridge=0,artp=0;
ll check[10001], num[10001], low[10001], parent[10001],art[10001];
void dfs(ll i,vector<ll>a[]){
	check[i]=1; timer++;
	ll cnt=0;
	low[i]=num[i]=timer;
	for(auto x:a[i]){
		if(check[x]==0){
			parent[x]=i;
			dfs(x,a);
			if(low[x]>=num[i]) art[i]=1;
			low[i]=min(low[x],low[i]);
			cnt++;
			if(num[x]==low[x]) bridge++;
		}
		else if(x!=parent[i]) {
			low[i]=min(low[i],num[x]);
		}
	}
	if(parent[i]==-1){
		if(cnt>1) {
			art[i]=1; artp++;
		}
	}
	else{
		if(art[i]==1) artp++;
	}
}
int main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.oup","w",stdout);
	cin>>n>>e;
	vector<ll>a[n+1];
	f(i,1,e){
		ll c,d;
		cin>>c>>d;
		a[c].push_back(d);
		a[d].push_back(c);
	}
	f(i,1,n){
		check[i]=0;
		parent[i]=-1;
		art[i]=0;
	}
	f(i,1,n){
		if(check[i]==0) dfs(i,a);
	}
	//f(i,1,n) cout<<i<<" "<<low[i]<<  " "<<num[i]<<endl;
	cout<<artp<<" "<<bridge;
}
*/
