#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define piii pair<ll,pair<ll,ll>>
#define pii pair<ll,ll
ll r[1100][1100],parent[1100],check[1100];
vector<ll>g[1100];
ll m,n,s=0,t;
ll inf=1000001;
ll bfs(){
	f(i,0,t) {
		check[i]=0; 
		parent[i]=-1;
	}
	queue<ll>q;
	q.push(s);
	check[s]=1;
	while(!q.empty()){
		ll i=q.front();
		q.pop();
		for(auto x:g[i]){
			if(check[x]==0&&r[i][x]==1){
				q.push(x);
				check[x]=1;
				parent[x]=i;
				if(x==t) return 1;
			}
		}
	}
	return 0;
}
void edmondsKarp(){
	while(bfs()){
		ll x=t;
		while(1){
			if(x==s) break;
			ll p=parent[x];
			r[p][x]--;
			r[x][p]++;
			x=p;
		}
	}
}
ll lv[1100],pos[1100];
void bfslv(){
	f(i,0,t) lv[i]=0;
	lv[s]=1;
	queue<ll>q;
	q.push(s);
	while(!q.empty()){
		ll i=q.front();
		q.pop();
		for(auto x:g[i]){
			if(lv[x]==0&&r[i][x]==1){
				q.push(x);
				lv[x]=lv[i]+1;
			}
		}
	}
}
ll dfs(ll i){
	if (i==t) return 1;
	for(;pos[i]<g[i].size();pos[i]++){
		ll x=g[i][pos[i]];
		if(lv[x]!=lv[i]+1) continue;
		if(r[i][x]<=0) continue;
		ll y=dfs(x);
		if(y==1){
			r[i][x]--;
			r[x][i]++;
			return 1;
		}
	}
	return 0;
}
void dinic(){
	while(1){
		bfslv();
		if(lv[t]==0) break;
		f(i,0,t) pos[i]=0;
		while(1){
			ll x=dfs(s);
			if(x==0) break;
		}
	}
}
int main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.oup","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin.ignore();
	t=2*n+2*m+1;
	//sp: 1-n, th: n+1 -> 2n, prob1: 2n+1 -> 2n+m, prob2: 2n+m+1 -> 2n+2m
	f(i,1,n){
		g[s].push_back(i);
		g[i].push_back(s);
		g[n+i].push_back(t);
		g[t].push_back(n+i);
		r[s][i]=1;
		r[i][s]=0;
		r[n+i][t]=1;
		r[t][n+i]=0;
	}
	f(i,1,n){
		string s;
		getline(cin,s);
		stringstream ss;
		ss<<s;
		ll a;
		while(ss>>a){
			g[i].push_back(a+2*n);
			g[a+2*n].push_back(i);
			r[i][a+2*n]=1;
			r[a+2*n][i]=0;
		}
	}
	f(i,1,n){
		string s;
		getline(cin,s);
		stringstream ss;
		ss<<s;
		ll a;
		while(ss>>a){
			g[a+2*n+m].push_back(n+i);
			g[n+i].push_back(a+2*n+m);
			r[a+2*n+m][n+i]=1;
			r[n+i][a+2*n+m]=0;
		}
	}
	f(i,1,m){
		ll j=2*n+i;
		g[j].push_back(j+m);
		g[j+m].push_back(j);
		r[j][j+m]=1;
		r[j+m][j]=0;
	}
	dinic();
	//edmondsKarp();
	f(i,1,m){
		ll a=2*n+i;
		ll ans=0;
		f(j,1,n){
			if(r[a][j]==1) {
				ans=j;
				break;
			}
		}
		cout<<ans<< " ";
		ans=0;
		f(j,1,n){
		 	if(r[j+n][a+m]==1){
		 		ans=j;
		 		break;
			}
		}
		cout<<ans;
		cout<<endl;
	}
}
