
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

int arr[200005];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	stack<int>s;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		//s.push(i);
	}
	
	std::vector<int>ans;
	for (int i = 0; i<n; i++)
	{
		while(!s.empty() and arr[s.top()]>=arr[i]) {
			s.pop();
		}
		if(s.size()==0) ans.pb(0);
		else ans.pb(s.top()+1);
		s.push(i);
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
