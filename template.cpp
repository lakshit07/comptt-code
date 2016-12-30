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


int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif



  return 0;
}  

#define inchar getchar
#define outchar(x) putchar(x)
template <typename T> void in (T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template <typename T> void out (T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}

#define sz(a)  int((a).size())
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
ll mulmod(ll a,ll b, ll m){ll q=(ll)(((ld)a*(ld)b)/(ld)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T, typename S>T expo(T e, S n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return __gcd(a,b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}


// Basic graph algorithms
// BFS and DFS

vector<pair<int,int> >adj[100005];
bool visited[100005];
int parent[100005];

void bfs(int s)
{
  q.push(s);
  visited[s] = true;
  parent[s] = 1;

  while(!q.empty())
  {
  	t = q.front();
  	q.pop();

  	forc(adj[t] , it)
  	{
  		if(visited[*it] == false)
  		{
  			parent[*it] = t;
  			visited[*it] = true;
  			q.push(*it);
  		}
  	}
  }
}

void dfs(int s)
{
  visited[s] = true;

  forc(adj[s] , it)
  {
    if(!visited[*it])
      dfs(*it);
  }
}

// ___________________________________________


// Segment trees range queries

template<class T>
class SegmentTree
{
     int *A,size;
     public:
     SegmentTree(int N)
     {
          int x = (int)(ceil(log2(N)))+1;
          size = 2*(int)pow(2,x);
          A = new int[size];
          memset(A,-1,sizeof(A));
     }
     void initialize_max(int node, int start,
                         int end, T *array)
     {
 
          if (start==end)
             A[node] = start;
          else
          {
              int mid = (start+end)/2;
              initialize_max(2*node,start,mid,array);
              initialize_max(2*node+1,mid+1,end,array);
              if (array[A[2*node]]<=array[A[2*node+1]])
                 A[node] = A[2 * node + 1];
              else
                  A[node] = A[2 * node];
          }
     }

    void initialize_min(int node, int start,
                         int end, T *array)
     {
 
          if (start==end)
             A[node] = start;
          else
          {
              int mid = (start+end)/2;
              initialize_min(2*node,start,mid,array);
              initialize_min(2*node+1,mid+1,end,array);
              if (array[A[2*node]]<=array[A[2*node+1]])
                 A[node] = A[2 * node];
              else
                  A[node] = A[2 * node + 1];
          }
     }


     int query_max(int node, int start,
                   int end, int i, int j, T *array)
     {
         int id1,id2;
         if (i>end || j<start)
            return -1;
 
         if (start>=i && end<=j)
            return A[node];
 
         int mid = (start+end)/2;
         id1 = query_max(2*node,start,mid,i,j,array);
         id2 = query_max(2*node+1,mid+1,end,i,j,array);
 
         if (id1==-1)
            return id2;
         if (id2==-1)
            return id1;
 
         if (array[id1]<=array[id2])
            return id2;
         else
             return id1;
     }

    int query_min(int node, int start,
                   int end, int i, int j, T *array)
     {
         int id1,id2;
         if (i>end || j<start)
            return -1;
 
         if (start>=i && end<=j)
            return A[node];
 
         int mid = (start+end)/2;
         id1 = query_min(2*node,start,mid,i,j,array);
         id2 = query_min(2*node+1,mid+1,end,i,j,array);
 
         if (id1==-1)
            return id2;
         if (id2==-1)
            return id1;
 
         if (array[id1]<=array[id2])
            return id1;
         else
             return id2;
     }

};

// _____________________________________________

// Trie data structure with insertion and searching

struct trie
{
  int pr;
  struct trie* alpha[26];
};

typedef struct trie* node;
node temp;

node initialize()
{
  node n = (node)malloc(sizeof(struct trie));
  n->pr = 0;

  for0(i , 26)
    n->alpha[i] = NULL;

  return n;   
}

void insert(node root , string s , int prno)
{
  siz = s.size();
  temp = root;

  for0(i , siz)
  {
    if(!temp->alpha[s[i]-'a'])
    {
      node next = initialize();
      next->pr = prno;
      temp->alpha[s[i]-'a'] = next;
      temp = next;
    }
    else
    {
      temp = temp->alpha[s[i]-'a'];
      temp->pr = max(temp->pr , prno);
     }
  }
}

int search(node root , string s)
{
  siz = s.size();
  temp = root;

  for0(i , siz)
  {
   if(temp->alpha[s[i]-'a'] == NULL)
    return -1;
   else
   {
      temp = temp->alpha[s[i]-'a'];
      if(i == siz-1)
        return temp->pr;
   }
  }
}

// --------------------------------------------------- 