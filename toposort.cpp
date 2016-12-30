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

int n , m , x , y;
vector<int> adj[MAX];
vector<int> order;
vector<int> indeg(MAX , 0);
queue<int> q;
vector<bool> visited(MAX , false);

void topo()
{
	forab(i , 1 , n)
	{
		if(indeg[i] == 0)
		{
			visited[i] = true;
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		order.pb(x);

		forc(adj[x] , it)
		{
			indeg[*it]--;

			if(indeg[*it] == 0)
			{
				q.push(*it);
				visited[*it] = true;
			}
		}
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
  	indeg[y]++;
  }

  topo();

  forc(order , it)
  	cout<<*it<<" ";



  return 0;
} 
