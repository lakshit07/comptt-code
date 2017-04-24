#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 100005

int n, d;
int a[MAX];
int tree[3*MAX];
// Range max query segment tree

void build(int node, int l, int r)
{
	if(l > r)
		return;

	if(l == r)
		tree[node] = a[l];
	else
	{
		build(2*node, l, (l+r)/2);
		build(2*node+1 , 1 + (l+r)/2 , r);
		tree[node] = max(tree[2*node], tree[2*node + 1]);
	}
}

// range update from i..j with value 'value'
void update(int node, int l, int r, int i, int j, int value)
{
	if(i > r || j < l || l > r)
		return;

	if(l == r)
		tree[node] += value;
	else
	{
		update(2*node , l , (l+r)/2 , i , j , value);
		update(2*node + 1 , (l+r)/2 + 1 , r , i , j , value);
		tree[node] = max(tree[2*node] , tree[2*node + 1]);	
	}
}

//range max query in [i..j]
int query(int node, int l, int r, int i, int j)
{
	if(i > r || j < l || l > r)
		return INT_MIN;

	if(l == r)
		return tree[node];

	return max(query(2*node, l , (l+r)/2, i, j) , query(2*node + 1 , (l+r)/2 + 1 , r , i , j));
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif


  return 0;
}  