
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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n,m;
int visited[1002][1002];
ll dist[1002][1002];
char grid[1002][1002];
pair<pii,char>par[1002][1002];
std::map<int,char>dir;

// void dfs(int x,int y){
// 	vis[x][y] = 1;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		int x1 = x+dx[i];
// 		int y1 = y+dy[i];
// 		if(x1>=0 && x1<n && y1>=0 && y1<m && dist[x1][y1]>1+dist[x][y] && (grid[x1][y1]=='.' || grid[x1][y1]=='B')){
// 			par[x1][y1] = mp(mp(x,y),dir[i]);
// 			dist[x1][y1] = 1+dist[x][y];
// 			dfs(x1,y1);
// 		}
// 	}
// }

bool f(int x,int y) {
	if(x==1 && y-1>0 && y+1<=m && grid[x][y-1]=='M' || grid[x][y+1]=='M') return 0;
	if(x==n && y-1>0 && y+1<=m && grid[x][y-1]=='M' || grid[x][y+1]=='M') return 0;
	if(y==1 && x-1>0 && x+1<=n && grid[x-1][y]=='M' || grid[x+1][y]=='M') return 0;
	if(y==m && x-1>0 && x+1<=n && grid[x-1][y]=='M' || grid[x+1][y]=='M') return 0;
	return 1;
}

void bfs(int x,int y){
	dist[x][y] = 0;
	queue<pii>q;
	q.push(mp(x,y));
	visited[x][y]=1;
	while(!q.empty()){
		pii node = q.front();
		q.pop();
		//cout<<"hello"<<endl;
		for (int i = 0; i < 4; ++i)
		{
			int x1 = node.first+dx[i];
			int y1 = node.second+dy[i];
			if(x1>0 && x1<=n && y1>0 && y1<=m && !visited[x1][y1] && (grid[x1][y1]=='.') && f(x1,y1)){
				par[x1][y1] = mp(mp(node.first,node.second),dir[i]);
				dist[x1][y1] = 1+dist[node.first][node.second];
				visited[x1][y1] = 1;
				q.push(mp(x1,y1));
			}
		}
	}
}

bool compare(pii a,pii b){
	return dist[a.f][a.s]>dist[b.f][b.s];
}



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dir[0] = 'U';
	dir[1] = 'D';
	dir[2] = 'L';
	dir[3] = 'R';
	cin>>n>>m;
	int sx,sy;
	std::vector<pii> ep;
	for (int i = 1; i <= n; ++i)
	{
		for(int j=1;j<=m;j++) {
			cin>>grid[i][j];
			if(grid[i][j]=='A') sx=i,sy=j;
			dist[i][j] = mod;
			visited[i][j]=0;
			if(grid[i][j]=='.' && (i==1 || j==1 || i==n || j==m)) ep.pb(mp(i,j));
		}
	}
	if(sx==1 || sx == n || sy==1 || sy==m) {
		cout<<"YES\n0";
		return 0;
	}
	bfs(sx,sy);
	sort(ep.begin(), ep.end(),compare);
	for(int i=0;i<ep.size();i++) {
		int ex = ep[i].f,ey = ep[i].s;
		if(visited[ex][ey] && f(ex,ey)) {
		cout<<"YES\n";
		cout<<dist[ex][ey]<<endl;
		string s = "";
		int val = dist[ex][ey];
		int cnt=0;
		while(cnt<val) {
			s += par[ex][ey].second;
			int x = par[ex][ey].first.first;
			int y = par[ex][ey].first.second;
			ex = x;
			ey = y;
			cnt++;
		}
		reverse(s.begin(),s.end());
		cout<<s;
		return 0;
		}
	}
	
	cout<<"NO\n";
	return 0;
}
