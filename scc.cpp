#include <bits/stdc++.h>
 using namespace std;
typedef long long int ll ;
typedef long double ld;

#define MOD 1000000007ll

#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
#define for0(i,n) for(__typeof(n) i = 0; i < n ; i++) 
#define forab(i,a,b) for(__typeof(a) i = a ; i < b ; i++) 
#define forba(i,b,a) for(__typeof(a) i = b ; i > a ; i--) 
#define forc(c,it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define pb     push_back
#define mp     make_pair
#define MAX 100005

vector<bool> visited(MAX, false);
vector<int> adj[MAX];
vector<int> adjr[MAX];
int n,m,x,y;
stack<int> q;
vector<int> comp[MAX];
int noc;
int c ,d;

int dfs(int v)
{
	visited[v] = true;
	q.push(v);

	forc(adj[v] , it)
	{
		if(!visited[*it])
			dfs(*it);
	}
}

void rev()
{
	forab(i , 1  , n+1)
	{
		forc(adj[i] , it)
			adjr[*it].pb(i);
	}
}

void scc(int s)
{
	visited[s] = true;
	comp[noc].pb(s);

	forc(adjr[s] , it)
	{
		if(!visited[*it])
			scc(*it);
	}
}



int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif

  cin>>n>>m;

  for0(i , m)
  {
  	cin>>x>>y;
  	adj[x].pb(y);
  }

  forab(i , 1 , n+1)
  {
    if(!visited[i])
      dfs(i);
  }

  rev();

  for0(i , n+1)
  	visited[i] = false;

  while(!q.empty())
  {
  	int x = q.top();
  	q.pop();

  	if(!visited[x])
  	{
  		scc(x);
  		noc++;
  	}
  }	

  for0(i , noc)
  {
  	forc(comp[i] , it)
  		cout<<*it<<" ";
  	cout<<endl;	
  }

  return 0;
} 
