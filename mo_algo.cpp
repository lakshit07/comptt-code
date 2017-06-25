#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
const int MOD = 1e9+7;
const int MAX = 1e5+5;

vector<pair<pair<int,int>, int> > query;
int ans[MAX];
int n, q, l, r, cnt, BLOCK_SIZE;
vector<int> a;

bool mo_cmp(pair< pair<int, int>, int> x, pair< pair<int, int>, int> y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

void add(int x)
{
	
}

void remove(int x)
{
	
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  scanf("%d", &n);
  BLOCK_SIZE = static_cast<int>(sqrt(n));

  for(int i = 0 ; i < q ; i++)
  {
  	scanf("%d %d", &l, &r);
  	l--, r--;
  	query.pb(mp(mp(l, r), i));
  }

  sort(all(query), mo_cmp);
  int mo_left = 0;
  int mo_right = -1;

  for(int i = 0 ; i < q ; i++)
  {
  	int lft = query[i].first.first;
  	int rgt = query[i].first.second;

  	while(mo_right < rgt) 
  	{
        mo_right++;
        add(a[mo_right]);
    }
    
    while(mo_right > rgt) 
    {
        remove(a[mo_right]);
        mo_right--;
    }

    while(mo_left < lft) {
        remove(a[mo_left]);
        mo_left++;
    }
    
    while(mo_left > lft) {
    	mo_left--;
    	add(a[mo_left]);
    }

    ans[query[i].second] = cnt;

  }

  for(int i = 0 ; i < q ; i++){
  	printf("%d\n", ans[i]);
  }

  return 0;
}  
