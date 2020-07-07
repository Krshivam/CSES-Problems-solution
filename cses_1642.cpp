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

std::map<ll,pll>m;
pll arr[1001];
ll n,x;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>x;
	for (ll i = 0; i < n; ++i)
	{
		cin>>arr[i].first;
		arr[i].second = i;
	}
	for (ll i = 0; i < n; ++i)
	{

		for (ll j = i+1; j < n; ++j)
		{
			m[arr[i].first+arr[j].first] = mp(i,j);
		}
	}
	//sort(arr,arr+n);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i==j) continue;
			if(m.count(x-(arr[i].first+arr[j].first))){

				pii t = m[x-(arr[i].first+arr[j].first)];
				if(arr[i].second!=t.first && arr[i].second!=t.second && arr[j].second!=t.first && arr[j].second!=t.second){
					//cout<<i<<" "<<j<<" "<<x-(arr[i].first+arr[j].first)<<endl;

					//cout<<arr[i].first<<" "<<arr[j].first<<" "<<arr[t.first].first<<" "<<arr[t.second].first<<endl;
					//cout<<m[10].first<<" "<<m[10].second<<endl;
					//cout<<
					cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<t.first+1<<" "<<t.second+1;
					return 0;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
