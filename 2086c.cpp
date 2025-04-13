#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
class DSU
{
public:
      vector<ll> par;
      vector<ll> tot;

      DSU(ll n)
      {
            par.resize(n + 1, 0);
            tot.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                  par[i] = i;
      }

      ll findPar(ll u)
      {
            if (par[u] == u)
                  return u;

            return par[u] = findPar(par[u]);
      }

      void unionBySize(ll u, ll v)
      {
            ll a = findPar(u);
            ll b = findPar(v);
            if (a == b)
                  return;

            ll sa = tot[a];
            ll sb = tot[b];

            if (sa < sb)
            {
                  tot[b] += tot[a];
                  par[a] = b;
            }
            else
            {
                  tot[a] += tot[b];
                  par[b] = a;
            }
      }
};
void solve(ll test)
{
      int n;
      cin >> n;

      vector<int> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      DSU ds(n + 2);
      for (int i = 1; i <= n; i++)
      {
            int a = i;
            int b = v[i - 1];
            ds.unionBySize(a, b);
      }

      vector<int> vis(n + 2, 0);
      int ans = 0;

      for (int i = 1; i <= n; i++)
      {
            int num;
            cin >> num;

            int father = ds.findPar(num);

            if (vis[father] == 0)
            {
                  ans += ds.tot[father];
                  vis[father] = 1;
            }
            cout << ans << " ";
      }
      cout << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}