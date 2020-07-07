
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

pair<pii,int>arr[200005];
int ans[200005];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].f.s>>arr[i].f.f;
		arr[i].s = i;
	}
	sort(arr,arr+n);
	set<pii>s1;
	for (int i = 0; i < n; ++i)
	{
		set<pii>::iterator it = s1.lower_bound(mp(arr[i].f.s,-mod));
		if(it!=s1.begin()){
			it--;
			ans[arr[i].s] = (*it).s;
			s1.erase(it);
		}
		else {
			ans[arr[i].s] = s1.size();
		}
		s1.insert(mp(arr[i].f.f,ans[arr[i].s]));
	}
	cout<<s1.size()<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<ans[i]+1<<" ";
	}
	return 0;
}
