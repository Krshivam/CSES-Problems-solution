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

string s;
std::map<int, char> m;
int x=0,y=0;
pii arr[4] = {mp(0,1),mp(-1,0),mp(0,-1),mp(1,0)};
ll ans = 0;

bool possible(int id,int k) {
	if(s[k]!='?') return 1;
	if(x+arr[id].f>=0 && x+arr[id].f<7 && arr[id].s>=0 && arr[id].s<7) return 1;
	return 0;
}

bool f(int k) {
	//if(x<0 || x>=7 || y<0 || y>=7) return 0;
	if(k==48) {
		if(x==0 && y==6) ans+=1;
		return 1;
	}
	ll ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		if(possible(i,k)){
			x+=arr[i].f,y+=arr[i].s;
			if(f(k+1)) {
				return 1;
			}
			else {
				x-=arr[i].f,y-=arr[i].s;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	m['U'] = 0;
	m['L'] = 1;
	m['D'] = 2;
	m['R'] = 3;
	cin>>s;
	cout<<f(0);
	cout<<ans;
	return 0;
}
