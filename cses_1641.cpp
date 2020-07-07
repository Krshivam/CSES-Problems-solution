
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
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

ll arr[5001];
std::map<ll,std::vector<int> > m;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll x;
	cin>>n>>x;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		m[arr[i]].pb(i);
	}
	sort(arr,arr+n);
	for (int i = 0; i < n; ++i)
	{
		ll t = x-arr[i];
		if(t<=0) continue;
		for(int j=0;j<n;j++){
			if(j==i) continue;
			ll y = t-arr[j];
			if(binary_search(arr,arr+n,y)){
				int idx = lower_bound(arr,arr+n,y)-arr;
				//cout<<i<<" "<<j<<" "<<idx<<endl;
				if(idx!=j && idx!=i){
					map<ll,int>m1;
					cout<<m[arr[i]][m1[arr[i]]]+1<<" ";
					m1[arr[i]]++;
					cout<<m[y][m1[y]]+1<<" ";
					m1[y]++;
					cout<<m[arr[j]][m1[arr[j]]]+1;
					//m1[arr[i]]++;
					return 0;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
