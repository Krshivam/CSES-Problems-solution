
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

std::vector<ll> v,v1;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll sm = (n*(n+1))/2;
	//cout<<sm<<endl;
	if(sm%2) cout<<"NO";
	else{
		cout<<"YES\n";
		
		ll sm1 = sm/2;
		ll i = n;
		while(sm1>0 && i>0){
			if(sm1-i>=0) {
				v.pb(i);
				sm1-=i;
			}
			i--;
		}
		cout<<v.size()<<"\n";
		for (int k = 0; k < v.size(); ++k)
		{
			cout<<v[k]<<" ";
		}
		reverse(v.begin(), v.end());
		ll j=n;
		ll sm2 = sm/2;
		while(sm2>0 && j>0) {
			if(sm2-j>=0 && !binary_search(v.begin(),v.end(),j)){
				v1.pb(j);
				sm2-=j;
			}
			j--;
		}
		cout<<"\n";
		cout<<v1.size()<<"\n";
		for (int k = 0; k < v1.size(); ++k)
		{
			cout<<v1[k]<<" ";
		}
	}
	return 0;
}
