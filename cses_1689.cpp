
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

int x,y;
int tr[10][10];

int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
std::vector<pii> v;

int dfs(int x,int y,int cnt) {
	if(cnt==64){
		return 1;
	}
	for (int i = 0; i < 8; ++i)
	{
		int x1 = x+dx[i];
		int y1 = y+dy[i];
		if(x1>=1 && x1<=8 && y1>=1 && y1<=8 && !tr[x1][y1]) {
			tr[x1][y1] = cnt;
			if(dfs(x1,y1,cnt+1)){
				return 1;
			}
			else tr[x1][y1] = 0;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y;
	swap(x,y);
	//memset(vis,0,sizeof(vis));
	tr[x][y] = 1;
	int ans = dfs(x,y,1);

	for (int i =1; i <=8; ++i)
	{
		for(int j=1;j<=8;j++) {
			cout<<tr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
