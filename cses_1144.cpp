
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define inp(x) cin>>x
#define print(x) cout<<x
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define reset(d,val) memset(d,val,sizeof(d))
#define sort(v) sort(v.begin(),v.end())
#define sort_arr(arr,i,f) sort(arr+i,arr+f)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

const int MXN = 200005;

std::vector<int>tree[4*MXN];
ll arr[MXN];

void build(int l,int r,int node){
	//if(tree[node].size()<(r-l+1)) tree[node].resize(r-l+1);
	if(l==r){
	 tree[node].pb(arr[l]);
	 return;
	}
	int mid = (l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,node<<1|1);
	merge(tree[node<<1].begin(), tree[node<<1].end(), tree[node<<1|1].begin(),
		tree[node<<1|1].end(), back_inserter(tree[node]));
}

void update(int l,int r,int idx,int val,int node){
	if(l==r) {
		tree[node][0]=val;
		return;
	}
	int mid = (l+r)>>1;
	if(idx<=mid) update(l,mid,idx,val,node<<1);
	else update(mid+1,r,idx,val,node<<1|1);
	merge(tree[node<<1].begin(), tree[node<<1].end(), tree[node<<1|1].begin(),
		tree[node<<1|1].end(), back_inserter(tree[node]));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	build(0,n-1,1);
	while(q--){
		char id;
		cin>>id;
		if(id=='?') {
			int l,r;
			cin>>l>>r;
			//l--,r--;
			ll ridx = upper_bound(tree[1].begin(),tree[1].end(),r)-tree[1].begin();
			ll lidx = lower_bound(tree[1].begin(),tree[1].end(),l)-tree[1].begin();
			cout<<ridx-lidx<<endl;
		}
		else{
			int idx,val;
			cin>>idx>>val;
			idx--;
			update(0,n-1,idx,val,1);
		}
	}
	return 0;
}
