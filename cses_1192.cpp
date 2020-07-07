
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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

char grid[1001][1001];
int vis[1001][1001];
int n,m;

void dfs(int x,int y){
	vis[x][y]=1;
	for (int i = 0; i < 4; ++i)
	{
		int x1 = x+dx[i];
		int y1 = y+dy[i];
		if(x1>=0 && x1<n && y1>=0 && y1<m && !vis[x1][y1] && grid[x1][y1]=='.'){
			dfs(x1,y1);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++) cin>>grid[i][j],vis[i][j]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++) {
			if(!vis[i][j] && grid[i][j]=='.') {
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
