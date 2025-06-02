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
    freopen("in.inp","r",stdin);
    ll n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<piii>edge(m+1);
    cout<<"Edge List:"<<endl;
    f(i,1,m){
        ll a,b,v;
        cin>>a>>b>>v;
        edge[i].fi=v;
        edge[i].se.fi=a;
        edge[i].se.se=b;
        cout<<a<<" "<<b<< " "<<v<<endl;
    }
    ll cnt=n,ans=0;
    while(cnt>1){
        vector<ll>cheap(n+1,-1); 
        f(i,1,m){
            ll a=dsu.find(edge[i].se.se);
            ll b=dsu.find(edge[i].se.fi);
            ll val=edge[i].fi;
            if(a==b) continue;
            if(cheap[a]==-1||edge[cheap[a]].fi>val) cheap[a]=i;
            if(cheap[b]==-1||edge[cheap[b]].fi>val) cheap[b]=i;
        }
        f(i,1,n){
            if(cheap[i]==-1) continue;
            piii e=edge[cheap[i]];
            if(!dsu.Union(e.se.se,e.se.fi)) continue;
            ans+=e.fi;
            cnt--;
        }
    }
    cout<<"MST: ";
    cout<<ans;

}

