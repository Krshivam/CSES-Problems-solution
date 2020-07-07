
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

int prime[1000005];
ll cnt[1000005];

void euler(){
	for(ll i=2;i<=1000000;i++){
		if(!prime[i]){
			for(ll j = i;j<=1000000;j+=i){
				if(i!=j) prime[j]=1;
				ll x = 0;
				ll y = j;
				while(y%i==0){
					y/=i;
					x++;
				}
				cnt[j] *= (x+1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0;i<=1000000;i++) cnt[i] = 1,prime[i]=0;
	euler();
	
	int n;
	cin>>n;
	while(n--){
		ll a;
		cin>>a;
		cout<<cnt[a]<<"\n";
	}
	return 0;
}
